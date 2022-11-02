{$r-,q-,s-,i-,o+}
{$M 10000000}
var
  a,nom:array[0..500500]of longint;
  n,i:longint;
  g:array[1..2,0..500500]of longint;
  kg:array[1..2]of longint;

  procedure qs(l,r:longint);
    var
      i,j,xx,tmp:longint;

    begin
      i:=l;j:=r;
      xx:=a[l+random(r-l+1)];
      while (i<=j)do begin
        while (xx>a[i])do inc(i);
        while (xx<a[j])do dec(j);
        if (i>j)then break;
        tmp:=a[i];a[i]:=a[j];a[j]:=tmp;
        tmp:=nom[i];nom[i]:=nom[j];nom[j]:=tmp;
        inc(i);dec(j);
      end;
      if (i<r)then qs(i,r);
      if (j>l)then qs(l,j);
    end;

begin
  randomize;
  read(n);
  kg[1]:=0;kg[2]:=0;
  for i:=1 to n do read(a[i]);
  for i:=1 to n do nom[i]:=i;
  qs(1,n);
  i:=1;
  while (i<=n)do begin
    inc(kg[1]);
    g[1][kg[1]]:=nom[i];
    if (i+1>n)then break;
    inc(kg[2]);
    g[2][kg[2]]:=nom[i+1];
    inc(i,2);
  end;
  writeln(kg[1]);
  for i:=1 to kg[1] do write(g[1][i],' ');
  writeln;
  writeln(kg[2]);
  for i:=1 to kg[2] do write(g[2][i],' ');
  writeln;
end.