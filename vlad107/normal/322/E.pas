{$r-,q-,s-,i-,o+}
{$M 10000000}
var
  size,rev,g,pred,last:array[0..500500]of longint;
  was:array[0..500500]of boolean;
  ans:array[0..500500]of char;
  m,nom,min,i,kg,n,x,y:longint;

  procedure dfs1(x,px:longint);
    var
      ii:longint;
      
    begin
      ii:=last[x];
      size[x]:=1;
      while (ii>0)do begin
        if (not was[rev[ii]])and(g[ii]<>px)then begin
          dfs1(g[ii],x);
          inc(size[x],size[g[ii]]);
        end;
        ii:=pred[ii];
      end;
    end;
    
  procedure dfs2(x,px:longint);
    var
      cr,ii:longint;
      
    begin
      ii:=last[x];
      cr:=m-size[x];
      while (ii>0)do begin
        if (not was[rev[ii]])and(g[ii]<>px)then begin
          dfs2(g[ii],x);
          if (size[g[ii]]>cr)then cr:=size[g[ii]];
        end;
        ii:=pred[ii];
      end;
      if (cr<min)then begin
        min:=cr;
        nom:=x;
      end;
    end;

  procedure dfs(x:longint;ch:char);
    var
      ii:longint;
    begin
      dfs1(x,0);
      m:=size[x];
      min:=100500;
      nom:=x;
      dfs2(x,0);
      ans[nom]:=ch;
      ii:=last[nom];
      while (ii>0)do begin
        if (not was[rev[ii]])then begin
          was[rev[ii]]:=true;
          dfs(g[ii],chr(ord(ch)+1));
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
    inc(kg);g[kg]:=y;pred[kg]:=last[x];last[x]:=kg;rev[kg]:=i;
    inc(kg);g[kg]:=x;pred[kg]:=last[y];last[y]:=kg;rev[kg]:=i;
  end;
  fillchar(was,sizeof(was),false);
  dfs(1,'A');
  for i:=1 to n do write(ans[i],' ');
  writeln;
end.