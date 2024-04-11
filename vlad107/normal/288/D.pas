{$r-,q-,s-,i-,o+}
var
  f,o,t:array[0..500500]of qword;
  x,y,n,i,kg:longint;
  res:qword;
  pred,last,g:array[0..500500]of longint;

  procedure dfs(x,px:longint);
    var
      ii,y:longint;
      
    begin
      ii:=last[x];
      t[x]:=1;f[x]:=0;
      while (ii>0)do begin
        y:=g[ii];
        if (y<>px)then begin
          dfs(y,x);
          f[x]:=f[x]+t[x]*t[y];
          inc(t[x],t[y]);
        end;
        ii:=pred[ii];
      end;
    end;
    
  procedure dfs2(x,px:longint);
    var
      ii,y:longint;
      
    begin
      ii:=last[x];
      while (ii>0)do begin
        y:=g[ii];
        if (y<>px)then begin
          o[y]:=o[x]+f[y];
          dfs2(y,x);
        end;
        ii:=pred[ii];
      end;
    end;

begin
  read(n);
  kg:=0;
  fillchar(last,sizeof(last),$0);
  for i:=1 to n-1 do begin
    read(x,y);
    inc(kg);g[kg]:=y;pred[kg]:=last[x];last[x]:=kg;
    inc(kg);g[kg]:=x;pred[kg]:=last[y];last[y]:=kg;
  end;
  dfs(1,0);
  o[1]:=f[1];
  dfs2(1,0);
  res:=int64(n)*(n-1) div 2;
  res:=res*res;
  for i:=1 to n do res:=res+f[i]*(o[i]*2-f[i]-t[i]*(n-t[i]))-o[i]*(n-1);
  writeln(res);
end.