var
  n,m,s,hei,bai:int64;
  i,j:longint;
  a:array[1..500,1..500] of longint;
function k(color:int64):int64;
var
  o:longint;
  sum:int64;
begin
  sum:=1;
  for o:=1 to color do
   sum:=sum*2;
  k:=sum-1
end;
begin
  readln(n,m);
  s:=0;
  hei:=0;
  bai:=0;
  for i:=1 to n do
   begin
     for j:=1 to m do
      read(a[i,j]);
     readln
   end;
  for i:=1 to n do
   begin
     for j:=1 to m do
      if a[i,j]=1 then
      inc(hei)
       else inc(bai);
     inc(s,k(hei));
     inc(s,k(bai));
     hei:=0;
     bai:=0
   end;
  for i:=1 to m do
   begin
     for j:=1 to n do
      if a[j,i]=1 then
      inc(hei)
       else inc(bai);
     inc(s,k(hei));
     inc(s,k(bai));
     hei:=0;
     bai:=0
   end;
  dec(s,n*m);
  write(s)
end.