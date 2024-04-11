{$r-,q-,s-,i-,o+}
const
  inf:int64=1000000000000000000;
  
var
  x,y,z,it,qqq,n,i,kg:longint;
  x1,x2,cr,min1,min2,res,ans:int64;
  w,sz,p,used,g,pred,last,nom:array[0..500500]of longint;
  f,u:array[0..500500]of int64;
  
  procedure dfs(x,px:longint);
    var
      ii:longint;
    begin
      inc(cr);
      used[x]:=qqq;
      ii:=last[x];
      sz[x]:=1;
      while (ii>0)do begin
        if (g[ii]<>px)and(nom[ii]<>it)then begin
          dfs(g[ii],x);
          sz[x]:=sz[x]+sz[g[ii]];
        end;
        ii:=pred[ii];
      end;
    end;
    
  procedure dfs2(x,px,nx:longint);
    var
      ii:longint;
    begin
      ii:=last[x];
      f[x]:=f[x]+int64(n-2*sz[x])*nx;
      u[x]:=u[x]+nx;
      res:=res+int64(nx)*sz[x]*(n-sz[x]);
      while (ii>0)do begin
        if (g[ii]<>px)and(nom[ii]<>it)then begin
          f[g[ii]]:=f[x];
          u[g[ii]]:=u[x];
          dfs2(g[ii],x,p[ii]);
        end;
        ii:=pred[ii];
      end;
    end;

begin
  //assign(input,'input.txt');reset(input);
  read(n);
  kg:=0;
  fillchar(last,sizeof(last),$0);
  for i:=1 to n-1 do begin
    read(x,y,z);w[i]:=z;
    inc(kg);g[kg]:=y;p[kg]:=z;pred[kg]:=last[x];last[x]:=kg;nom[kg]:=i;
    inc(kg);g[kg]:=x;p[kg]:=z;pred[kg]:=last[y];last[y]:=kg;nom[kg]:=i;
  end;
  fillchar(used,sizeof(used),$0);
  qqq:=0;ans:=inf;
  for it:=1 to n-1 do begin
    inc(qqq);
    cr:=0;
    res:=0;
    dfs(1,0);
    f[1]:=0;u[1]:=0;
    dfs2(1,0,0);
    x1:=cr;
    cr:=0;
    for i:=2 to n do 
      if (used[i]<>qqq)then begin
        inc(qqq);
        dfs(i,0);
        f[i]:=0;u[i]:=0;
        dfs2(i,0,0);
        break;
      end;
    x2:=cr;
    min1:=inf;min2:=inf;
    res:=res+int64(x1)*x2*w[it];
    for i:=1 to n do begin
      if (used[i]=qqq-1)then begin
        cr:=int64(x2)*f[i]-int64(x2)*x2*u[i];
        if (cr<min1)then min1:=cr;
      end else begin
        cr:=int64(x1)*f[i]-int64(x1)*x1*u[i];
        if (cr<min2)then min2:=cr;
      end;
    end;
    if (res+min1+min2<ans)then ans:=res+min1+min2;
  end;
  writeln(ans);
end.