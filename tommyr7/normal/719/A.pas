var n,i:longint;
    a:array[1..100] of longint;
begin
  readln(n);
  fillchar(a,sizeof(a),0);
  for i:=1 to n do
	read(a[i]);
  readln;
  if (a[n]=0) then writeln('UP')
  else if (a[n]=15) then writeln('DOWN')else
  if (n=1) then writeln('-1')
  else if (a[n]<a[n-1]) or (a[n]=15) then writeln('DOWN') 
  else writeln('UP');
end.