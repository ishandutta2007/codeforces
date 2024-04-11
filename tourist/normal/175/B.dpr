{$R-,S-,Q-,I-,O+}
var
  cp,id,nn,n,i,j,better: longint;
  ch: char;
  sl: ansistring;
  name: array [0..1010] of ansistring;
  pts: array [0..1010] of longint;
begin
  read(nn);
  n:=0;
  for i:=1 to nn do
  begin
    read(ch);
    while not (ch in ['a'..'z']) do read(ch);
    sl:='';
    while ch in ['a'..'z'] do
    begin
      sl:=sl+ch;
      read(ch);
    end;
    id:=0;
    for j:=1 to n do
      if name[j] = sl then
      begin
        id:=j;
        break;
      end;
    if id = 0 then
    begin
      inc(n);
      name[n]:=sl;
      pts[n]:=0;
      id:=n;
    end;
    read(cp);
    if cp > pts[id] then pts[id]:=cp;
  end;
  writeln(n);
  for i:=1 to n do
  begin
    better:=0;
    for j:=1 to n do
      if pts[j] > pts[i] then inc(better);
    write(name[i],' ');
    if 2*better > n then writeln('noob') else
    if 5*better > n then writeln('random') else
    if 10*better > n then writeln('average') else
    if 100*better > n then writeln('hardcore')
    else writeln('pro');
  end;
end.