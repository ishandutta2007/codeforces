var
  tt,n,m,i,j:longint;
  a:array[0..500500]of longint;
  used:array[0..500500]of boolean;

begin
  read(n,m);
  for i:=1 to m do begin
    read(a[i]);
    used[a[i]]:=true;
  end;
  for i:=1 to m do begin
    tt:=n;
    for j:=1 to n*m do 
      if (not used[j])then begin
        write(j,' ');
        used[j]:=true;
        dec(tt);
        if (tt=1)then break;
      end;
    writeln(a[i]);
  end;
end.