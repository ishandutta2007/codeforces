type
  tstring=string;
const
  MAXN=10000;
var
  i,j,n,m,mx,my,x,y,res:longint;
  s:array[1..MAXN]of tstring;
  a:array[1..50,1..50]of char;
  n2,nom:array[1..MAXN]of longint;
  procedure qs(l,r:longint);
    var
      x,tmp:tstring;
      y,i,j,tn:longint;
    begin
      i:=l;j:=r;
      x:=s[(i+j)shr 1];
      y:=n2[(i+j)shr 1];
      while (i<=j)do begin
        while (x>s[i])or(x=s[i])and(y>n2[i])do inc(i);
        while (x<s[j])or(x=s[j])and(y<n2[j])do dec(j);
        if (i>j)then break;
        tmp:=s[i];s[i]:=s[j];s[j]:=tmp;
        tn:=nom[i];nom[i]:=nom[j];nom[j]:=tn;
        tn:=n2[i];n2[i]:=n2[j];n2[j]:=tn;
        inc(i);dec(j);
      end;
      if (i<r)then qs(i,r);
      if (j>l)then qs(l,j);
    end;
  function ok(x,y:longint):boolean;
    var
      a1,a2,i,j,ko,ka,i2,j2:longint;
    begin
      if (x=y)then begin
        a1:=1;a2:=1;
      end else begin
        a1:=1;a2:=2;
      end;
      i:=1;j:=1;
      ko:=0;
      ka:=0;
      while (i<=n)and(j<=m)do begin
        inc(ko);
        inc(ka);
        s[ka]:='';
        for i2:=i to i+x-1 do
          for j2:=j to j+y-1 do s[ka]:=s[ka]+a[i2][j2];
        nom[ka]:=ko;
        n2[ka]:=a1;
        inc(ka);
        s[ka]:='';
        for j2:=j to j+y-1 do
          for i2:=i+x-1 downto i do s[ka]:=s[ka]+a[i2][j2];
        nom[ka]:=ko;
        n2[ka]:=a2;
        inc(ka);
        s[ka]:='';
        for j2:=j+y-1 downto 1 do
          for i2:=i to i+x-1 do s[ka]:=s[ka]+a[i2][j2];
        nom[ka]:=ko;
        n2[ka]:=a2;
        inc(ka);
        s[ka]:='';
        for i2:=i+x-1 downto i do
          for j2:=j+y-1 downto j do s[ka]:=s[ka]+a[i2][j2];
        nom[ka]:=ko;
        n2[ka]:=a1;
        inc(j,y);
        if (j>m)then begin
          inc(i,x);
          j:=1;
        end;
      end;
      qs(1,ka);
      for i:=2 to ka do
        if (s[i]=s[i-1])and(nom[i]<>nom[i-1])and(n2[i]=n2[i-1])then begin
          ok:=false;exit;
        end;
      ok:=true;
    end;
begin
  readln(n,m);
  for i:=1 to n do begin
    for j:=1 to m do read(a[i][j]);
    readln;
  end;
  mx:=10000;
  my:=10000;
  res:=0;
  for x:=1 to n do for y:=1 to m do
    if (n mod x=0)and(m mod y=0)and(ok(x,y))then begin
      inc(res);
      if (x*y<mx*my)or(x*y=mx*my)and(x<mx)then begin
        mx:=x;my:=y;
      end;
    end;
  writeln(res);
  writeln(mx,' ',my);
end.