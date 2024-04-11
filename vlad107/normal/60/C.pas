{$r-,q-,s-,i-,o+}
const
  maxa=1000000;
var
  x,y,ox,oy,n,m,i,j:longint;
  a:array[0..100500]of longint;
  kg:array[0..222]of longint;
  g,gcd,lcm:array[0..222,0..222]of longint;
  function ggcd(x,y:longint):longint;
    begin
      while (x>0)and(y>0)do
        if (x>y)then x:=x mod y else y:=y mod x;
      ggcd:=x+y;
    end;
  function dfs(x:longint):boolean;
    var
      i:longint;
    begin
      for i:=1 to kg[x] do begin
        if (int64(gcd[x][i])*lcm[x][i] div a[x]>maxa)then begin
          dfs:=false;
          exit;
        end;
        if (int64(gcd[x][i])*lcm[x][i] mod a[x]>0)then begin
          dfs:=false;
          exit;
        end;
        if (a[g[x][i]]<>-1)and(int64(gcd[x][i])*lcm[x][i]div a[x]<>a[g[x][i]])then begin
          dfs:=false;
          exit;
        end;
        if (a[x] mod gcd[x][i]>0)then begin
          dfs:=false;
          exit;
        end;
        if (a[g[x][i]]<>-1)then continue;
        a[g[x][i]]:=int64(gcd[x][i])*lcm[x][i]div a[x];
        if (int64(a[x])*a[g[x][i]]div ggcd(a[x],a[g[x][i]])<>lcm[x][i])or(not dfs(g[x][i]))then begin
          dfs:=false;
          exit;
        end;
      end;
      dfs:=true;
    end;
  procedure dfs2(x:longint);
    var
      i:longint;
    begin
      if (a[x]<0)then exit;
      a[x]:=-1;
      for i:=1 to kg[x] do dfs2(g[x][i]);
    end;
begin
  read(n,m);
  for i:=1 to m do begin
    read(x,y,ox,oy);
    inc(kg[x]);g[x][kg[x]]:=y;gcd[x][kg[x]]:=ox;lcm[x][kg[x]]:=oy;
    inc(kg[y]);g[y][kg[y]]:=x;gcd[y][kg[y]]:=ox;lcm[y][kg[y]]:=oy;
  end;
  fillchar(a,sizeof(a),$FF);
  for i:=1 to n do 
    if (a[i]<0)then begin
      if (kg[i]=0)then begin
        a[i]:=1;
        continue;
      end;
      j:=1;
      while (j*j<=lcm[i][1])do begin
        if (lcm[i][1]mod j=0)then begin
          if (j mod gcd[i][1]=0)then begin
            a[i]:=j;
            if (dfs(i))then break;
            dfs2(i);
          end;
          if ((lcm[i][1] div j) mod gcd[i][1]=0)then begin
            a[i]:=lcm[i][1] div j;
            if (dfs(i))then break;
            dfs2(i);
          end;
        end;
        inc(j);
      end;
      if (j*j>lcm[i][1])then begin
        writeln('NO');
        exit;
      end;
    end;
  writeln('YES');
  for i:=1 to n do write(a[i],' ');
  writeln;
end.