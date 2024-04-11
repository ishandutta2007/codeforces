const
  km:array[1..12]of longint=(31,28,31,30,31,30,31,31,30,31,30,31);

var
  max,i,j,m,d,p,t,l,r,n:longint;
  u,fm:array[-500500..500500]of longint;
  

begin
  assign(input,'input.txt');reset(input);
  assign(output,'output.txt');rewrite(output);
  fm[0]:=0;
  for i:=1 to 12 do fm[i]:=fm[i-1]+km[i];
  read(n);
  for i:=1 to n do begin
    read(m,d,p,t);
    r:=fm[m-1]+d-1;
    l:=r-t+1;
    for j:=l to r do inc(u[j],p);
  end;
  max:=0;
  for i:=-1111 to 1111 do 
    if (u[i]>max)then max:=u[i];
  writeln(Max);
end.