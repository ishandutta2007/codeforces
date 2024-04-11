{$r-,q-,s-,i-,o+}
var
  res:int64;
  y,nx,kg,x,n,k,i,j:longint;
  prx,g,pred,last:array[0..200500]of longint;
  f:array[0..50500,0..555]of longint;

  procedure dfs(x,px:longint);
    var
      i,ii,y:longint;
      
    begin
      prx[x]:=px;
      f[x][0]:=1;
      for i:=1 to k do f[x][i]:=0;
      ii:=last[x];
      while (ii>0)do begin
        y:=g[ii];
        if (y<>px)then dfs(y,x);
        ii:=pred[ii];
      end;
      if (px=0)then exit;
      for i:=0 to k-1 do inc(f[px][i+1],f[x][i]);
    end;

begin
  //assign(input,'input.txt');reset(input);
  //assign(output,'output.txt');rewrite(output);
  read(n,k);
  kg:=0;
  for i:=1 to n-1 do begin
    read(x,y);
    inc(kg);g[kg]:=y;pred[kg]:=last[x];last[x]:=kg;
    inc(kg);g[kg]:=x;pred[kg]:=last[y];last[y]:=kg;
  end;
  
  fillchar(f,sizeof(f),$FF);
  dfs(1,0);
  
  res:=0;
  for i:=1 to n do begin
    x:=i;
    nx:=-1;
    for j:=0 to k do begin
      if (x=0)then break;
      res:=res+f[x][k-j];
      if (j<>0)and(k-j-1>=0)then res:=res-f[nx][k-j-1];
      nx:=x;
      x:=prx[x];
    end;
  end;
  writeln(res div 2);
  close(output);close(input);
end.