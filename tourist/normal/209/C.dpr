{$R-,S-,Q-,I-,O+}
var
  ii,n,m,i,j,e,kc,ans: longint;
  c,ss,ff,pred,last,deg,x: array [0..2000010] of longint;
  was: array [0..2000010] of boolean;
begin
  read(n,m);
  for i:=1 to m do
  begin
    read(ss[i],ff[i]);
    ss[i+m]:=ff[i];
    ff[i+m]:=ss[i];
  end;
  fillchar(last,sizeof(last),0);
  for i:=1 to m+m do
  begin
    pred[i]:=last[ss[i]];
    last[ss[i]]:=i;
  end;
  fillchar(deg,sizeof(deg),0);
  for i:=1 to m+m do inc(deg[ss[i]]);
  fillchar(was,sizeof(was),False);
  kc:=0;
  for ii:=1 to n do
    if not was[ii] then
    begin
      inc(kc);
      i:=1; e:=1;
      x[1]:=ii;
      was[ii]:=True;
      while i <= e do
      begin
        j:=last[x[i]];
        while j > 0 do
        begin
          if not was[ff[j]] then
          begin
            inc(e);
            x[e]:=ff[j];
            was[x[e]]:=True;
          end;
          j:=pred[j];
        end;
        inc(i);
      end;
      if (ii > 1) and (e = 1) and (deg[ii] = 0) then
      begin
        dec(kc);
        continue;
      end;
      c[kc]:=0;
      for i:=1 to e do
        if deg[x[i]] and 1 = 1 then inc(c[kc]);
    end;
  if kc = 1 then ans:=c[1] else
  begin
    ans:=0;
    for i:=1 to kc do
      if c[i] = 0 then inc(ans,2)
      else inc(ans,c[i]);
  end;
  writeln(ans div 2);
end.