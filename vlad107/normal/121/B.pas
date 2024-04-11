var
  s:ansistring;
  x,n,k,i,j:longint;
  was:Array[0..500500]of longint;

begin
  readln(n,k);
  readln(s);
  j:=1;
  fillchar(was,sizeof(was),$FF);
  i:=0;
  while (i<k)do begin
    inc(i);
    dec(j);
    if (j<1)then j:=1;
    while (j<n)and((s[j]<>'4')or(s[j+1]<>'7'))do inc(j);
    if (j=n)then break;
    if (j and 1=1)then s[j+1]:='4'else s[j]:='7';
    if (was[j]<>-1)then begin
      x:=i-was[j];
      i:=(k-i)mod x;
      k:=i;
      i:=0;
      fillchar(was,sizeof(was),$FF);
      continue;
    end;
    was[j]:=i;
  end;
  writeln(s);
end.