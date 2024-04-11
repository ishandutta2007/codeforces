{$r-,q-,s-,i-,o+}
var
  used:array[0..500500]of longint;
  f,g,pred,last:array[0..500500]of longint;
  ii,j,kol,x,y,kg,n,i:longint;
  
  procedure dfs(x,px:longint);
    var
      ii,y:longint;
      
    begin
      f[x]:=1;
      ii:=last[x];
      while (ii>0)do begin
        y:=g[ii];
        if (y<>px)then begin
          dfs(y,x);
          inc(f[x],f[y]);
        end;
        ii:=pred[ii];
      end;
    end;

begin
  read(n);
  for i:=1 to n-1 do begin
    read(x,y);
    inc(kg);g[kg]:=y;pred[kg]:=last[x];last[x]:=kg;
    inc(kg);g[kg]:=x;pred[kg]:=last[y];last[y]:=kg;
  end;
  fillchar(used,sizeof(used),$0);
  for i:=1 to n do begin
    dfs(i,0);
    ii:=last[i];
    used[0]:=i;
    while (ii>0)do begin
      x:=f[g[ii]];
      for j:=n-x downto 0 do
        if (used[j]=i)then used[j+x]:=i;
      ii:=pred[ii];
    end;
  end;
  kol:=0;
  for i:=1 to n-2 do 
    if (used[i]<>0)then inc(kol);
  writeln(kol);
  for i:=1 to n-2 do 
    if (used[i]<>0)then writeln(i,' ',n-i-1);
end.