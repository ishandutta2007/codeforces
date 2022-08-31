var n,i,k,a,b:integer;
x,y:array [1..100100] of integer;

function comp(x1,y1,x2,y2:integer):boolean;
begin
if y2>=0 then
  begin
  if y1<0 then comp:=false else
    begin
    if abs(x1)=abs(x2) then
      begin
      if y1<y2 then comp:=true else comp:=false;
      end else
      begin
      if abs(x1)<abs(x2) then comp:=true else comp:=false;
      end;
    end;
  end else
  begin
  if y1>=0 then comp:=true else
    begin
    if abs(x1)=abs(x2) then
      begin
      if y1>y2 then comp:=true else comp:=false;
      end else
      begin
      if abs(x1)<abs(x2) then comp:=true else comp:=false;
      end;
    end;
  end;
end;

procedure qsort(a,b:integer);
var i,j,z,mx,my:integer;
begin
if a>=b then exit;
i:=a;
j:=a+random(b-a+1);
mx:=x[j];
my:=y[j];
j:=b;
while i<=j do
  begin
  while comp(x[i],y[i],mx,my) do i+=1;
  while comp(mx,my,x[j],y[j]) do j-=1;
  if i<=j then
    begin
    z:=x[i];
    x[i]:=x[j];
    x[j]:=z;
    z:=y[i];
    y[i]:=y[j];
    y[j]:=z;
    i+=1;
    j-=1;
    end;
  end;
qsort(a,j);
qsort(i,b);
end;

begin
readln(n);
for i:=1 to n do readln(x[i],y[i]);
qsort(1,n);
k:=0;
for i:=1 to n do
  begin
  if y[i]<>0 then k+=2;
  if x[i]<>0 then k+=2;
  k+=2;
  end;
writeln(k);
for i:=1 to n do
  begin
  if y[i]<>0 then
    begin
    if y[i]>0 then
      begin
      writeln('1 ',y[i],' U');
      end else
      begin
      writeln('1 ',-y[i],' D');
      end;
    end;
  if x[i]<>0 then
    begin
    if x[i]>0 then writeln('1 ',x[i],' R') else writeln('1 ',-x[i],' L');
    end;
  writeln(2);
  if x[i]<>0 then
    begin
    if x[i]>0 then writeln('1 ',x[i],' L') else writeln('1 ',-x[i],' R');
    end;
  if y[i]<>0 then
    begin
    if y[i]>0 then writeln('1 ',y[i],' D') else writeln('1 ',-y[i],' U');
    end;
  writeln(3);
  end;
end.