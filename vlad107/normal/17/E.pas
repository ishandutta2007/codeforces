{$r-,q-,s-,i-,o+}
const
  maxn=4000005;
  base=51123987;

var
  p,s,ss:ansistring;
  ll,rr,ccc,ls,j,sl,fl,sr,fr,n,i:longint;
  ns,z:array[0..maxn]of longint;
  st,ft:array[0..maxn]of int64;
  c1,c2,res,cs:int64;
  
  function min(x,y:longint):longint;inline;
    begin
      if (x<y)then min:=x else min:=y;
    end;

begin
  //assign(input,'input.txt');reset(input);
  readln(n);
  readln(s);
  p:=s[1];
  for i:=2 to length(s)do p:=p+'#'+s[i];
  ss:=s;
  s:=p;
  ns[0]:=0;
  for i:=1 to length(s)do ns[i]:=ns[i-1]+ord(s[i]<>'#');
  ns[i+1]:=ns[i];
  z[0]:=0;
  ls:=length(s);ccc:=0;
  ll:=0;rr:=0;
  for i:=1 to ls do begin
    if (ll<=i)and(rr>=i)then j:=min(z[ll]+ll-i,z[ll-(i-ll)]) else j:=1;
    while (i-j>=1)and(i+j<=ls)and(s[i-j]=s[i+j])do begin
      inc(j);
      //inc(ccc);
    end;
    if (i+j>rr)then begin ll:=i;rr:=i+j; end;
    cs:=cs+ns[i]-ns[i-j];
    z[i]:=j;
    if (z[i]=1)and(s[i]='#')then continue;
    j:=z[i];
    if (s[i-j+1]='#')then dec(j);
    sl:=ns[i-j+1];
    sr:=ns[i];
    fl:=ns[i+1];
    fr:=ns[i+j-1];
    inc(st[sl]);dec(st[sr+1]);
    inc(ft[fl]);dec(ft[fr+1]);
  end;
  //writeln(ccc);
  st[n+1]:=0;st[0]:=0;
  ft[n+1]:=0;ft[0]:=0;
  for i:=1 to n do st[i]:=st[i-1]+st[i];
  for i:=n downto 1 do st[i]:=st[i]+st[i+1];
  for i:=1 to n do ft[i]:=ft[i-1]+ft[i];
  for i:=1 to n do st[i]:=st[i] mod base;
  for i:=1 to n do ft[i]:=ft[i] mod base;
  res:=0;
  for i:=1 to n do res:=(res+ft[i]*st[i+1])mod base;
  if (cs=0)then begin 
    writeln(0);
    exit;
  end;
  c1:=cs;c2:=cs-1;
  if (c1 mod 2=0)then c1:=c1 div 2 else c2:=c2 div 2;
  c1:=c1 mod base;c2:=c2 mod base;
  cs:=c1*c2;
  res:=(cs mod base)-res;
  if (res<0)then res:=res+base;
  res:=res mod base;
  writeln(res);
end.