{$r-,q-,s-,i-,o+}
var
  v,r1,r2,m,j,n,i:longint;
  a,b:array[0..200500]of longint;
  s:string;
  ch:char;
  name:array[0..200500]of string;
  procedure qsa(l,r:longint);
    var
      yy,tmp:string;
      t2,nom,xx,i,j:longint;
    begin
      i:=l;j:=r;
      nom:=l+random(r-l+1);
      xx:=a[nom];
      yy:=name[nom];
      while (i<=j)do begin
        while (xx<a[i])or(xx=a[i])and(yy>name[i])do inc(i);
        while (xx>a[j])or(xx=a[j])and(yy<name[j])do dec(j);
        if (i>j)then break;
        tmp:=name[i];name[i]:=name[j];name[j]:=tmp;
        t2:=a[i];a[i]:=a[j];a[j]:=t2;
        inc(i);dec(j);
      end;
      if (i<r)then qsa(i,r);
      if (j>l)then qsa(l,j);
    end;
  procedure qsb(l,r:longint);
    var
      xx,i,j,tmp:longint;
    begin
      i:=l;j:=r;
      xx:=b[(i+j)shr 1];
      while (i<=j)do begin
        while (xx>b[i])do inc(i);
        while (xx<b[j])do dec(j);
        if (i>j)then break;
        tmp:=b[i];b[i]:=b[j];b[j]:=tmp;
        inc(i);dec(j);
      end;
      if (i<r)then qsb(i,r);
      if (j>l)then qsb(l,j);
    end;
begin
  randomize;
  readln(n);
  for i:=1 to n do begin
    s:='';
    read(ch);
    while (ch in['a'..'z'])do begin
      s:=s+ch;
      read(ch);
    end;
    name[i]:=s;
    readln(a[i]);
  end;
  qsa(1,n);
  readln(m);
  for i:=1 to m do read(b[i]);
  for i:=m+1 to n do b[i]:=0;
  m:=n;
  readln;
  readln(s);
  qsb(1,m);
  for i:=1 to n do
    if (name[i]=s)then begin
      v:=a[i]+b[m];
      break;
    end;
  j:=1;
  r1:=1;
  for i:=1 to m-1 do begin
    while (true)do begin
      if (j>n)then begin
        r1:=n-i+1;
        break;
      end;
      if (name[j]=s)then begin
        inc(j);continue;
      end;
      if (a[j]+b[i]<v)or(a[j]+b[i]=v)and(name[j]>s)then break;
      inc(j);
    end;
    if (r1<>1)then break;
    inc(j);
  end;
  write(r1,' ');
  for i:=1 to n do
    if (name[i]=s)then begin
      v:=a[i]+b[1];
      break;
    end;
  j:=n;
  r2:=n;
  for i:=m downto 2 do begin
    while (true)do begin
      if (j=0)then begin
        r2:=n-i+1;
        break;
      end;
      if (name[j]=s)then begin
        dec(j);continue;
      end;
      if (a[j]+b[i]>v)or(a[j]+b[i]=v)and(name[j]<s)then break;
      dec(j);
    end;
    if (r2<>n)then break;
    dec(j);
  end;
  writeln(r2);
end.