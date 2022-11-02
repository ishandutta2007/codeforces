{$r-,q-,s-,i-,o+}
var
  ch:char;
  q,nom,qqq,x,y,kol,cr,res,n,m,i,j:longint;
  a:array[0..5555,0..5555]of char;
  f:array[0..5005,0..5005]of longint;
  g,pg:array[0..5555,0..5]of longint;
  function next(x,y,k:longint):longint;
    var
      nom:longint;
    begin
      if (f[x][y]<>qqq)then begin
        if (k and 1=1)then next:=x else next:=y;
        exit;
      end;
      nom:=(x-1)*m+y;
      if (k and 1=1)
        then pg[nom][k]:=next(pg[nom][k],y,k)
        else pg[nom][k]:=next(x,pg[nom][k],k);
      next:=pg[nom][k];
    end;
  procedure dfs(i,j:longint);
    var
      x,y:longint;
    begin
      if (i<1)or(j<1)or(i>n)or(j>m)then exit;
      f[i][j]:=qqq;
      inc(cr);
      x:=i;y:=j;
      nom:=(x-1)*m+y;
      case (a[i][j])of
        'U':begin
              pg[nom][1]:=next(x,y,1);
              x:=pg[nom][1];
            end;
        'R':begin
              pg[nom][2]:=next(x,y,2);
              y:=pg[nom][2];
            end;
        'D':begin
              pg[nom][3]:=next(x,y,3);
              x:=pg[nom][3];
            end;
        'L':begin
              pg[nom][4]:=next(x,y,4);
              y:=pg[nom][4];
            end;
      end;
      dfs(x,y);
    end;
begin
  readln(n,m);
  for i:=1 to n do begin
    for j:=1 to m do read(a[i][j]);
    readln;
  end;
  fillchar(f,sizeof(f),$0);
  for i:=1 to n do
    for j:=1 to m do
      if (a[i][j]<>'.')then begin
        nom:=(i-1)*m+j;
        x:=i-1;y:=j;
        while (x>0)and(a[x][y]='.')do dec(x);
        g[nom][1]:=x;

        x:=i;y:=j+1;
        while (y<=m)and(a[x][y]='.')do inc(y);
        g[nom][2]:=y;

        x:=i+1;y:=j;
        while (x<=n)and(a[x][y]='.')do inc(x);
        g[nom][3]:=x;

        x:=i;y:=j-1;
        while (y>0)and(a[x][y]='.')do dec(y);
        g[nom][4]:=y;
      end;
  qqq:=0;
  for i:=1 to n do
    for j:=1 to m do
      if (a[i][j]<>'.')then begin
        for q:=1 to n*m do pg[q]:=g[q];
        inc(qqq);
        cr:=0;
        dfs(i,j);
        if (cr>res)then begin
          res:=cr;kol:=0;
        end;
        if (cr=res)then inc(kol);
      end;
  writeln(res,' ',kol);
end.