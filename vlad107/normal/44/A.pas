var
  n,res,i,j:longint;
  a:array[1..111]of string;
begin
  readln(n);
  for i:=1 to n do begin
    readln(a[i]);
    inc(res);
    for j:=1 to i-1 do 
      if (a[i]=a[j])then begin
        dec(res);
        break;
      end;
  end;
  writeln(res);
end.