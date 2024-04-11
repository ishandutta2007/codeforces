{$R-,S-,Q-,I-,O+}
var
  x,y,z: array [0..1000010] of longint;
  a: array [0..1,0..500010] of char;
  was: array [0..1,0..500010] of boolean;
  n,k,i,j,e: longint;
  ch: char;
begin
  read(n,k);
  fillchar(a,sizeof(a),'-');
  for i:=0 to 1 do
    for j:=1 to n do
    begin
      read(ch);
      while not (ch in ['-','X']) do read(ch);
      a[i,j]:=ch;
    end;
  fillchar(was,sizeof(was),False);
  x[1]:=0; y[1]:=1;
  z[1]:=1;
  was[0,1]:=True;
  i:=1; e:=1;
  while i <= e do
  begin
    if y[i] > n then
    begin
      writeln('YES');
      halt;
    end;
    if not was[x[i],y[i]-1] then
      if (a[x[i],y[i]-1] = '-') and (z[i]+1 <= y[i]-1) then
      begin
        inc(e);
        x[e]:=x[i];
        y[e]:=y[i]-1;
        z[e]:=z[i]+1;
        was[x[e],y[e]]:=True;
      end;
    if not was[x[i],y[i]+1] then
      if a[x[i],y[i]+1] = '-' then
      begin
        inc(e);
        x[e]:=x[i];
        y[e]:=y[i]+1;
        z[e]:=z[i]+1;
        was[x[e],y[e]]:=True;
      end;
    if not was[1-x[i],y[i]+k] then
      if a[1-x[i],y[i]+k] = '-' then
      begin
        inc(e);
        x[e]:=1-x[i];
        y[e]:=y[i]+k;
        z[e]:=z[i]+1;
        was[x[e],y[e]]:=True;
      end;
    inc(i);
  end;
  writeln('NO');
end.