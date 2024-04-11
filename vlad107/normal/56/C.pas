var
  z,s:ansistring;
  j,res,n,i:longint;
  a:array[1..10000]of ansistring;
begin
  readln(s);
  n:=0;
  res:=0;
  z:='';
  for i:=1 to length(s)do
    if (s[i]in['A'..'Z'])
      then z:=z+s[i]
      else begin
        if (z<>'')then begin
          for j:=1 to n do if (a[j]=z)then inc(res);
          inc(n);
          a[n]:=z;
        end;
        z:='';
        if (s[i]='.')then dec(n);
      end;
  writeln(res);
end.