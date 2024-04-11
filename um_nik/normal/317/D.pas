var s,i,j,k,n,m,ans:integer;
a,b:array [0..50000] of integer;
c:array [1..30] of integer;
x,y:int64;

begin
readln(n);
m:=trunc(sqrt(n));
for i:=1 to m do a[i]:=0;
k:=0;
for i:=2 to m do
  begin
  if a[i]=0 then
    begin
    k+=1;
    b[k]:=0;
    x:=i;
    y:=i;
    while x<=n do
      begin
      b[k]+=1;
      if x<=50000 then a[x]:=1;
      x*=y;
      end;
    end;
  end;

c[1]:=1;
c[2]:=2;
c[3]:=1;
c[4]:=4;
c[5]:=3;
c[6]:=2;
c[7]:=1;
c[8]:=5;
c[9]:=6;
c[10]:=2;
c[11]:=1;
c[12]:=8;
c[13]:=7;
c[14]:=5;
c[15]:=9;
c[16]:=8;
c[17]:=7;
c[18]:=3;
c[19]:=4;
c[20]:=7;
c[21]:=4;
c[22]:=2;
c[23]:=1;
c[24]:=10;
c[25]:=9;
c[26]:=3;
c[27]:=6;
c[28]:=11;
c[29]:=12;
c[30]:=14;


ans:=n;
for i:=1 to k do ans-=b[i];
ans:=ans mod 2;
for i:=1 to k do ans:=ans xor c[b[i]];
if ans=0 then writeln('Petya') else writeln('Vasya');
end.