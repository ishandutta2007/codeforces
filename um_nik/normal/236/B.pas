var a,b,c,i,j,k,s,p:integer;
t:array [1..25] of integer;

function f(x:integer):integer;
var i,k,p:integer;
begin
k:=1;
p:=1;
for i:=1 to 25 do
begin
p:=p*k;
k:=1;
while x mod t[i]=0 do
begin
k:=k+1;
x:=x div t[i];
end;
if x=1 then break;
end;
f:=p*k;
end;

begin
t[1]:=2;
t[2]:=3;
t[3]:=5;
t[4]:=7;
t[5]:=11;
t[6]:=13;
t[7]:=17;
t[8]:=19;
t[9]:=23;
t[10]:=29;
t[11]:=31;
t[12]:=37;
t[13]:=41;
t[14]:=43;
t[15]:=47;
t[16]:=53;
t[17]:=59;
t[18]:=61;
t[19]:=67;
t[20]:=71;
t[21]:=73;
t[22]:=79;
t[23]:=83;
t[24]:=89;
t[25]:=97;
readln(a,b,c);
s:=0;
for i:=1 to a do
begin
for j:=1 to b do
begin
for k:=1 to c do
begin
s:=(s+f(i*j*k)) mod 1073741824;
end;
end;
end;
writeln(s);
end.