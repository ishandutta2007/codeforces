{R+,S+,Q+,I+,O-}
{$R-,S-,Q-,I-,O+}
const inf = round(1e9);
var
  f: array [0..55,0..55] of int64;
  g: array [0..55,0..55] of longint;
  best,worst,n,m,i,j,ss,ff,dd,g1,g2,s1,s2,k: longint;
  ans: int64;
  max,min: array [0..55] of longint;
  gold,silver,bronze: array [0..55] of boolean;
begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(n,m);
  for i:=1 to n do
    for j:=1 to n do
      if i <> j then g[i,j]:=inf
      else g[i,j]:=0;
  for i:=1 to m do
  begin
    read(ss,ff,dd);
    if dd < g[ss,ff] then
    begin
      g[ss,ff]:=dd;
      g[ff,ss]:=dd;
    end;
  end;
  for k:=1 to n do
    for i:=1 to n do
      for j:=1 to n do
        if g[i,k]+g[k,j] < g[i,j] then g[i,j]:=g[i,k]+g[k,j];
  for i:=1 to n do
  begin
    max[i]:=0; min[i]:=inf;
    for j:=1 to n do
      if i <> j then
      begin
        g[i,j]:=g[i,j]*100+i;
        if g[i,j] > max[i] then max[i]:=g[i,j];
        if g[i,j] < min[i] then min[i]:=g[i,j];
      end;
  end;
  read(g1,g2,s1,s2);
  ans:=0;
  for best:=1 to n do
    for worst:=1 to n do
      if (best <> worst) and (min[best] < max[worst]) then
      begin
        for i:=1 to n do
        begin
          gold[i]:=min[i] <= min[best];
          bronze[i]:=max[i] >= max[worst];
          silver[i]:=False;
          for j:=1 to n do
            if (i <> j) and (g[i,j] > min[best]) and (g[i,j] < max[worst]) then
            begin
              silver[i]:=True;
              break;
            end;
        end;
        gold[best]:=True; silver[best]:=False; bronze[best]:=False;
        gold[worst]:=False; silver[worst]:=False; bronze[worst]:=True;
        for i:=0 to n do
          for j:=0 to n do f[i,j]:=0;
        f[0,0]:=1;
        for k:=1 to n do
          for i:=n downto 0 do
            for j:=n downto 0 do
              if f[i,j] > 0 then
              begin
                if gold[k] then inc(f[i+1,j],f[i,j]);
                if silver[k] then inc(f[i,j+1],f[i,j]);
                if not bronze[k] then f[i,j]:=0;
              end;
        for i:=g1 to g2 do
          for j:=s1 to s2 do inc(ans,f[i,j]);
      end;
  writeln(ans);
  close(input);
  close(output);
end.