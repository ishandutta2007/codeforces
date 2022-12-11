var n,m,k,i,j,x,y,t,max,tot,ans:longint;
    father,a,other,next,last,num,sum:array[0..200087] of longint;
	flag:boolean;
procedure insert(x,y:longint);
begin
  inc(tot);
  other[tot]:=y;
  next[tot]:=last[x];
  last[x]:=tot;
  inc(num[x]);
end;
function fa(x:longint):longint;
begin
  if (father[x]<>x) then father[x]:=fa(father[x]);
  exit(father[x]);
end;
begin
  readln(n,m,k);
  fillchar(last,sizeof(last),0);
  fillchar(num,sizeof(num),0);
  for i:=1 to n do
  begin
    read(a[i]);
	father[i]:=i;
  end;
  flag:=true;
  for i:=2 to n do
	if (a[i]<>a[1]) then flag:=false;
  if flag then
  begin
    writeln('0');
    halt;
  end;
  for i:=1 to m do
  begin
    readln(x,y);
    if (fa(x)<>fa(y)) then father[fa(x)]:=fa(y);
  end;
  tot:=0;
  for i:=1 to n do
	insert(fa(i),i);
  fillchar(sum,sizeof(sum),0);
  ans:=0;
  for i:=1 to n do
	if (num[i]>0) then
	begin
	  max:=0;
	  j:=last[i];
	  while (j>0) do
	  begin
	    inc(sum[a[other[j]]]);
	    if (sum[a[other[j]]]>max) then max:=sum[a[other[j]]];
		j:=next[j];
	  end;
	  ans:=ans+num[i]-max;
	  j:=last[i];
	  while (j>0) do
	  begin
	    dec(sum[a[other[j]]]);
	    j:=next[j];
	  end;
	end;
  writeln(ans);
end.