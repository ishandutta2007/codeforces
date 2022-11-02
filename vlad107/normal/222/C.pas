{$r-,q-,s-,i-,o+}
const
  maxa=10000001;
  maxn=100500;
  maxp=3000000;
 
var
  lasta,lastb,prime:array[0..maxa+10]of longint;
  preda,predb,ga,gb:array[0..maxp]of longint;
  a,b:array[0..maxn+10]of longint;
  kga,kgb,ia,ib,x,y,n,m,i,j:longint;

begin
  for i:=1 to maxa do prime[i]:=i;
  for i:=2 to maxa do 
    if (prime[i]=i)then 
      for j:=2 to maxa div i do 
        if (prime[i*j]=i*j)then prime[i*j]:=i;
  read(n,m);
  for i:=1 to n do begin
    read(a[i]);
    x:=a[i];
    while (x>1)do begin
      inc(kga);ga[kga]:=i;preda[kga]:=lasta[prime[x]];lasta[prime[x]]:=kga;
      x:=x div prime[x];
    end;
  end;
  for i:=1 to m do begin
    read(b[i]);
    x:=b[i];
    while (x>1)do begin
      inc(kgb);gb[kgb]:=i;predb[kgb]:=lastb[prime[x]];lastb[prime[x]]:=kgb;
      x:=x div prime[x];
    end;
  end;
  for x:=2 to maxa do 
    if (prime[x]=x)then begin
      ia:=lasta[x];
      ib:=lastb[x];
      while (ia>0)and(ib>0)do begin
        i:=ga[ia];
        j:=gb[ib];
        a[i]:=a[i]div x;
        b[j]:=b[j]div x;
        ia:=preda[ia];
        ib:=predb[ib];
      end;
    end;
  writeln(n,' ',m);
  for i:=1 to n do write(a[i],' ');
  writeln;
  for i:=1 to m do write(b[i],' ');
  writeln;
end.