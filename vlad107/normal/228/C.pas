var
  ans,c1,c2,c3,c4,i1,j1,i2,j2,qt,n,m,i,j:longint;
  t,tt,a:array[0..555,0..555]of longint;
  ch:char;
  
  function f(a,b,c,d:longint):longint;
    begin
      f:=d+2*c+4*b+8*a;
    end;

begin
  //assign(input,'input.txt');reset(input);
  readln(n,m);
  for i:=1 to n do begin
    for j:=1 to m do begin
      read(ch);
      if (ch='.')then a[i][j]:=0 else a[i][j]:=1;
    end;
    readln;
  end;
  for i:=1 to n do 
    for j:=1 to m do 
      if (i+1<=n)and(j+1<=m)
        then t[i][j]:=f(a[i][j],a[i][j+1],a[i+1][j],a[i+1][j+1])
        else t[i][j]:=-1;
  ans:=0;
  for qt:=2 to 10 do begin
    for i1:=1 to n do 
      for j1:=1 to m do begin
        if (i1+1 shl qt-1>n)or(j1+1 shl qt-1>m)then begin
          tt[i1][j1]:=-1;
          continue;
        end;
        i2:=i1+1 shl (qt-1);
        j2:=j1+1 shl (qt-1);
        if (t[i1][j1]<0)or(t[i1][j2]<0)or(t[i2][j1]<0)or(t[i2][j2]<0)then begin
          tt[i1][j1]:=-1;
          continue;
        end;
        c1:=t[i1][j1];
        c2:=t[i1][j2];
        c3:=t[i2][j1];
        c4:=t[i2][j2];
        tt[i1][j1]:=f(ord(c1=15),ord(c2=15),ord(c3=15),ord(c4=15));
        if (c1<>15)and(c1<>tt[i1][j1])then tt[i1][j1]:=-1;
        if (c2<>15)and(c2<>tt[i1][j1])then tt[i1][j1]:=-1;
        if (c3<>15)and(c3<>tt[i1][j1])then tt[i1][j1]:=-1;
        if (c4<>15)and(c4<>tt[i1][j1])then tt[i1][j1]:=-1;
        if (tt[i1][j1]<>-1)
          then inc(ans);
      end;
    for i:=1 to n do 
      for j:=1 to m do begin
        t[i][j]:=tt[i][j];
        tt[i][j]:=-1;
      end;
  end;
  writeln(ans);
end.