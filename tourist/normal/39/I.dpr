{$R+,S+,Q+,I+,O-}
{R-,S-,Q-,I-,O+}
var
  n,m,i,j,aa,bb,e,t,k: longint;
  v,last,pred,was,ss,ff,x,y: array [0..400010] of longint;
  dist: array [0..400010,0..2] of longint;
begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(n,m);
  fillchar(last,sizeof(last),0);
  for i:=1 to m do
  begin
    read(ss[i],ff[i]);
    pred[i]:=last[ss[i]];
    last[ss[i]]:=i;
  end;
  fillchar(was,sizeof(was),0);
  fillchar(dist,sizeof(dist),0);
  i:=1; e:=1;
  x[1]:=1;
  y[1]:=1;
  was[1]:=1;
  dist[1,1]:=0;
  while i <= e do
  begin
    j:=last[x[i]];
    while j > 0 do
    begin
      if (was[ff[j]] < 2) and (dist[x[i],y[i]]+1 <> dist[ff[j],was[ff[j]]]) then
      begin
        inc(e);
        x[e]:=ff[j];
        inc(was[x[e]]);
        y[e]:=was[x[e]];
        dist[x[e],y[e]]:=dist[x[i],y[i]]+1;
      end;
      j:=pred[j];
    end;
    inc(i);
  end;
  t:=0;
  for i:=1 to n do
    if was[i] = 2 then
    begin
      aa:=t; bb:=dist[i,2]-dist[i,1];
      while (aa > 0) and (bb > 0) do
        if aa > bb then aa:=aa mod bb
        else bb:=bb mod aa;
      t:=aa+bb;
    end;
  for i:=1 to m do
    if (was[ss[i]] > 0) and (was[ff[i]] > 0) then
    begin
      aa:=t; bb:=abs(dist[ss[i],1]+1-dist[ff[i],1]);
      while (aa > 0) and (bb > 0) do
        if aa > bb then aa:=aa mod bb
        else bb:=bb mod aa;
      t:=aa+bb;
    end;
  k:=0;
  for i:=1 to n do
    if (was[i] > 0) and (dist[i,1] mod t = 0) then
    begin
      inc(k);
      v[k]:=i;
    end;
  writeln(t);
  writeln(k);
  for i:=1 to k-1 do write(v[i],' ');
  writeln(v[k]);
  close(input);
  close(output);
end.