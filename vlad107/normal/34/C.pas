var
  a:array[1..1000]of longint;
  i,n,j,m,tmp:longint;
  procedure getnum(var x:longint);
    var
      ch:char;
    begin
      read(ch);
      if (not (ch in ['0'..'9']))and(eof(input))then begin
        dec(n);
        exit;
      end;
      while not (ch in ['0'..'9'])do read(ch);
      x:=0;
      while (ch in['0'..'9'])do begin
        x:=x*10;
        x:=x+ord(ch)-48;
        read(ch);
      end;
    end;
begin
//  assign(input,'input.txt');reset(input);
  n:=0;
  while (not eof(input)) do begin
    inc(n);
    getnum(a[n]);
  end;
  for j:=1 to n-1 do for i:=1 to n-1 do
    if (a[i]>a[i+1])then begin
      tmp:=a[i];a[i]:=a[i+1];a[i+1]:=tmp;
    end;
  m:=1;
  for i:=1 to n do
    if (a[i]<>a[m])then begin
      inc(m);
      a[m]:=a[i];
    end;
  n:=m;
  i:=1;
  while (i<=n)do begin
    j:=i;
    while (j<n)and(a[j+1]-a[j]=1)do inc(j);
    if (j>i)
      then write(a[i], '-',a[j])
      else write(a[i]);
    if (j<n)then write(',');
    i:=j+1
  end;
  writeln;
end.