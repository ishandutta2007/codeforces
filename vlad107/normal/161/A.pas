{$r-,q-,s-,i-,o+}
var
  cr,x,y,n,m,i,j:longint;
  r1,r2,a,b,n1,n2:array[0..500500]of longint;

  procedure qs1(l,r:longint);
    var
      nn,i,j,tmp,xx:longint;
      
    begin
      i:=l;j:=r;
      nn:=l+random(r-l+1);
      xx:=a[nn];
      while (i<=j)do begin
        while (xx>a[i])do inc(i);
        while (xx<a[j])do dec(j);
        if (i>j)then break;
        tmp:=a[i];a[i]:=a[j];a[j]:=tmp;
        tmp:=n1[i];n1[i]:=n1[j];n1[j]:=tmp;
        inc(i);dec(j);
      end;
      if (i<r)then qs1(i,r);
      if (j>l)then qs1(l,j);
    end;

  procedure qs2(l,r:longint);
    var
      nn,i,j,tmp,xx:longint;
      
    begin
      i:=l;j:=r;
      nn:=l+random(r-l+1);
      xx:=b[nn];
      while (i<=j)do begin
        while (xx>b[i])do inc(i);
        while (xx<b[j])do dec(j);
        if (i>j)then break;
        tmp:=b[i];b[i]:=b[j];b[j]:=tmp;
        tmp:=n2[i];n2[i]:=n2[j];n2[j]:=tmp;
        inc(i);dec(j);
      end;
      if (i<r)then qs2(i,r);
      if (j>l)then qs2(l,j);
    end;

begin
  randomize;
  //assign(input,'input.txt');reset(input);
  //assign(output,'output.txt');rewrite(output);
  read(n,m,x,y);
  for i:=1 to n do begin
    read(a[i]);
    n1[i]:=i;
  end;
  qs1(1,n);
  for i:=1 to m do begin
    read(b[i]);
    n2[i]:=i;
  end;
  qs2(1,m);
  j:=1;
  cr:=0;
  for i:=1 to n do begin
    while (j<=m)and(b[j]<a[i]-x)do inc(j);
    if (j>m)then break;
    if (b[j]>a[i]+y)then continue;
    inc(cr);
    r1[cr]:=n1[i];
    r2[cr]:=n2[j];
    inc(j);
  end;
  writeln(cr);
  for i:=1 to cr do writeln(r1[i],' ',r2[i]);
  //close(output);close(input);
end.