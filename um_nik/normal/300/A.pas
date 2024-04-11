var i,n,x,k1,k2,k3:integer;
a1,a2,a3:array [1..100] of integer;
begin
readln(n);
k1:=0;
k2:=0;
k3:=0;
for i:=1 to n do
  begin
  read(x);
  if x=0 then k3+=1 else
    begin
    if x>0 then
      begin
      k2+=1;
      a2[k2]:=x;
      end else
      begin
      k1+=1;
      a1[k1]:=x;
      end;
    end;
  end;
if k1 mod 2=1 then
  begin
  if k2=0 then
    begin
    write(k1-2,' ');
    for i:=3 to k1 do write(a1[i],' ');
    writeln();
    writeln(2,' ',a1[1],' ',a1[2]);
    end else
    begin
    write(k1,' ');
    for i:=1 to k1 do write(a1[i],' ');
    writeln();
    write(k2,' ');
    for i:=1 to k2 do write(a2[i],' ');
    writeln();
    end;
  write(k3,' ');
  for i:=1 to k3 do write('0 ');
  writeln();
  end else
  begin
  if k2=0 then
    begin
    write(k1-3,' ');
    for i:=3 to k1-1 do write(a1[i],' ');
    writeln();
    writeln(2,' ',a1[1],' ',a1[2]);
    end else
    begin
    write(k1-1,' ');
    for i:=1 to k1-1 do write(a1[i],' ');
    writeln();
    write(k2,' ');
    for i:=1 to k2 do write(a2[i],' ');
    writeln();
    end;
  write(k3+1,' ');
  for i:=1 to k3 do write('0 ');
  writeln(a1[k1]);
  end;
end.