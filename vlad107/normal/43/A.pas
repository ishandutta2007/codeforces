var
  s1,s2:ansistring;
  a:array[1..10000] of ansistring;
  n,i,r1,r2:longint;

begin
  readln(n);
  for i:=1 to n do readln(a[i]);
  s1:=a[1];
  r1:=1;r2:=0;
  for i:=2 to n do 
    if (a[i]=s1)
      then inc(r1)
      else begin
        inc(r2);
        s2:=a[i];
      end;
  if (r1>r2)
    then writeln(s1)
    else writeln(s2);
end.