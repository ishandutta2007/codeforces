var
  res,a,b:array[1..100000]of longint;
  was:array[1..100000]of boolean;
  tmp,i,j,n,m:longint;
begin
  read(n);
  for i:=1 to n do read(a[i]);
  for i:=1 to n do read(b[i]);
  fillchar(was,sizeof(was),false);
  m:=0;
  for i:=1 to n do begin
    j:=i;
    while (b[j]<>a[i])do inc(j);
    while (j>i)do begin
      inc(m);
      res[m]:=j-1;
      tmp:=b[j];b[j]:=b[j-1];b[j-1]:=tmp;
      dec(j);
    end;
  end;
  writeln(m);
  for i:=1 to m do writeln(res[i],' ',res[i]+1);
end.