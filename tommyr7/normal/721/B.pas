var n,k,i,j,ans,now1,now2:longint;
    w:array[1..300] of string;
	r:string;
procedure qsort(lx,rx:longint);
var i,j,m:longint;
    t:string;
begin
  i:=lx;
  j:=rx;
  m:=length(w[(i+j) div 2]);
  repeat
	while (length(w[i])<m) do inc(i);
	while (length(w[j])>m) do dec(j);
	if (i<=j) then
	begin
	  t:=w[i];
	  w[i]:=w[j];
	  w[j]:=t;
	  inc(i);
	  dec(j);
	end;
  until (i>j);
  if (i<rx) then qsort(i,rx);
  if (j>lx) then qsort(lx,j);
end;
function tryit(x:longint):longint;
begin
  exit(x+5*((x-1) div k));
end;
begin
  readln(n,k);
  for i:=1 to n do
	readln(w[i]);
  readln(r);
  qsort(1,n);
  now1:=1;
  while (now1<=n) and (length(w[now1])<length(r)) do inc(now1);
  now2:=now1;
  while (now2<=n) and (length(w[now2])=length(r)) do inc(now2);
  dec(now2);
  writeln(tryit(now1),' ',tryit(now2));
end.