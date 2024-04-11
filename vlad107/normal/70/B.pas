var
  n,res,ka,r,i:longint;
  s,z:ansistring;
  a:array[0..1111]of ansistring;
  ksp:array[0..1111]of longint;

begin
  readln(n);
  readln(s);
  z:='';
  ka:=0;
  for i:=1 to length(s)do begin
    z:=z+s[i];
    if (s[i]in['.','!','?'])then begin
      inc(ka);
      a[ka]:=z;
      z:='';
    end;
  end;
  for i:=1 to ka do begin
    ksp[i]:=0;
    while (a[i][ksp[i]+1]=' ')do inc(ksp[i]);
  end;
  for i:=1 to ka do 
    if (length(a[i])-ksp[i]>n)then begin
      writeln('Impossible');
      exit;
    end;
  res:=1;
  r:=length(a[1])-ksp[1];
  for i:=2 to ka do 
    if (r+length(a[i])>n)then begin
      inc(res);
      r:=length(a[i])-ksp[i];
    end else inc(r,length(a[i]));
  writeln(res);
end.