{$R+,S+,Q+,I+,O-}
{R-,S-,Q-,I-,O+}
const inf = 1000000000;
var
  n,m,i,t,j,ans,k,p: longint;
  v: array [0..110] of longint;
  ss,ff,dd,f: array [0..100010] of longint;
  g: array [0..110,0..110] of longint;
  good,need: array [0..110] of boolean;
begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(n,m);
  for i:=1 to n do
    for j:=1 to n do
      if i = j then g[i,j]:=0
      else g[i,j]:=inf;
  fillchar(need,sizeof(need),False);
  ans:=0;
  for i:=1 to m do
  begin
    read(ss[i],ff[i],dd[i]);
    inc(ans,dd[i]);
    good[ss[i]]:=True;
    good[ff[i]]:=True;
    need[ss[i]]:=not need[ss[i]];
    need[ff[i]]:=not need[ff[i]];
    if g[ss[i],ff[i]] > dd[i] then
    begin
      g[ss[i],ff[i]]:=dd[i];
      g[ff[i],ss[i]]:=dd[i];
    end;
  end;
  for k:=1 to n do
    for i:=1 to n do
      for j:=1 to n do
        if g[i,k]+g[k,j] < g[i,j] then g[i,j]:=g[i,k]+g[k,j];
  for i:=1 to n do
      if (g[i,1] = inf) and (good[i]) then
      begin
        writeln(-1);
        halt;
      end;
  p:=0;
  for i:=1 to n do
    if need[i] then
    begin
      inc(p);
      v[p]:=i;
    end;
  for t:=0 to 1 shl p-1 do f[t]:=inf;
  f[0]:=0;
  for t:=0 to 1 shl p-2 do
    if f[t] < inf then
      for i:=1 to p do
        if (t and (1 shl (i-1))) = 0 then
          for j:=i+1 to p do
            if (t and (1 shl (j-1))) = 0 then
              if f[t]+g[v[i],v[j]] < f[t+(1 shl (i-1))+(1 shl (j-1))] then
                f[t+(1 shl (i-1))+(1 shl (j-1))]:=f[t]+g[v[i],v[j]];
  writeln(ans+f[1 shl p-1]);
  close(input);
  close(output);
end.