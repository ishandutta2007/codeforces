{$R-,S-,Q-,I-,O+}
var
  n,m,i,e,r,j,tmp: longint;
  pred,last,ss,ff,f,x: array [0..400010] of longint;
  d: array [1..2,0..400010] of boolean;
  was: array [0..400010] of boolean;
begin
  read(n,m);
  for i:=1 to n do read(f[i]);
  fillchar(last,sizeof(last),0);
  for i:=1 to m do
  begin
    read(ss[i],ff[i]);
    pred[i]:=last[ss[i]];
    last[ss[i]]:=i;
  end;
  for r:=1 to 2 do
  begin
    e:=0;
    for i:=1 to n do
      if f[i] = r then
      begin
        inc(e);
        x[e]:=i;
        was[i]:=True;
      end
      else was[i]:=False;
    i:=1;
    while i <= e do
      if (r = 2) and (f[x[i]] = 1) then inc(i) else
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
    for i:=1 to n do d[r,i]:=was[i];
    fillchar(last,sizeof(last),0);
    for i:=1 to m do
    begin
      tmp:=ss[i]; ss[i]:=ff[i]; ff[i]:=tmp;
      pred[i]:=last[ss[i]];
      last[ss[i]]:=i;
    end;
  end;
  for i:=1 to n do
    if d[1,i] and d[2,i] then writeln(1)
    else writeln(0);
end.