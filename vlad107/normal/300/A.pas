var
  ct,i,n:longint;
  a:array[0..500500]of longint;
  used:array[0..500500]of boolean;

begin
  read(n);
  for i:=1 to n do read(a[i]);
  write('1 ');
  for i:=1 to n do 
    if (a[i]<0)then begin
      writeln(a[i]);
      used[i]:=true;
      break;
    end;
  ct:=0;
  for i:=1 to n do 
    if (a[i]>0)then inc(ct);
  if (ct=0)then begin
    write('2 ');
    ct:=2;
    for i:=1 to n do 
      if (a[i]<0)and(not used[i])then begin
        dec(ct);
        write(a[i],' ');
        used[i]:=true;
        if (ct=0)then break;
      end;
    writeln;
  end else begin
    write(ct,' ');
    for i:=1 to n do 
      if (a[i]>0)then begin
        write(a[i],' ');
        used[i]:=true;
      end;
    writeln;
  end;
  ct:=0;
  for i:=1 to n do 
    if (not used[i])then inc(Ct);
  write(ct,' ');
  for i:=1 to n do 
    if (not used[i])then write(a[i],' ');
  writeln;
end.