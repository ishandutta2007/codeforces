{dp=1-right,2-down,3-left,4-up  }
{cp=1-left,2-right}
{$r-,q-,s-,i-,o+}
var
  dp,cp,i,j,n,m,t,x,y:longint;
  a:array[0..55,0..55]of char;
  left,right,down,up:array[0..55,0..55]of longint;
  s:string;

  procedure next(x,y,dp,cp:longint;var nx,ny:longint);
    begin
      if (dp=1)and(cp=1)then begin  
        nx:=up[x][y]+1;
        ny:=right[x][y];
      end else 
      if (dp=1)and(cp=2)then begin
        nx:=down[x][y]-1;
        ny:=right[x][y];
      end else
      if (dp=2)and(cp=1)then begin
        nx:=down[x][y];
        ny:=right[x][y]-1;
      end else
      if (dp=2)and(cp=2)then begin
        nx:=down[x][y];
        ny:=left[x][y]+1;
      end else
      if (dp=3)and(cp=1)then begin
        nx:=down[x][y]-1;
        ny:=left[x][y];
      end else 
      if (dp=3)and(cp=2)then begin
        nx:=up[x][y]+1;
        ny:=left[x][y];
      end else
      if (dp=4)and(cp=1)then begin
        nx:=up[x][y];
        ny:=left[x][y]+1;
      end else 
      if (dp=4)and(cp=2)then begin
        nx:=up[x][y];
        ny:=right[x][y]-1;
      end;
    end;

begin
  readln(n,t);
  readln(s);
  m:=length(s);
  for j:=1 to m do a[1][j]:=s[j];
  for i:=2 to n do begin
    for j:=1 to m do read(a[i][j]);
    readln;
  end;
  for i:=1 to n do 
    for j:=1 to m do 
      if (a[i][j]<>'0')then begin
        x:=j;
        while (a[i][x]=a[i][j])do dec(x);
        left[i][j]:=x;
        x:=j;
        while (a[i][x]=a[i][j])do inc(x);
        right[i][j]:=x;
        x:=i;
        while (a[x][j]=a[i][j])do dec(x);
        up[i][j]:=x;
        x:=i;
        while (a[x][j]=a[i][j])do inc(x);
        down[i][j]:=x;
      end;
  dp:=1;cp:=1;
  i:=1;j:=1;
  next(2,1,4,1,x,y);
  while (t>0)do begin
    dec(t);
    next(i,j,dp,cp,x,y);
    if (x<1)or(y<1)or(x>n)or(y>m)or(a[x][y]='0')then begin
      if (cp=2)then begin
        inc(dp);
        if (dp>4)then dp:=1;
      end;
      cp:=3-cp;
    end else begin
      i:=x;j:=y;
    end;
  end;
  writeln(a[i][j]);
end.