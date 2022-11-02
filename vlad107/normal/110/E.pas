{$r-,q-,s-,i-,o+}
var
  fr,fk,f,g,pred,last:array[0..500500]of longint;
  p:array[0..500500]of boolean;
  i,n,x,y,z,kg:longint;
  res:int64;
  procedure dfs(x,px:longint);
    var
      y,ii:longint;
    begin
      fk[x]:=1;
      f[x]:=0;
      ii:=last[x];
      while (ii>0)do begin
        y:=g[ii];
        if (y=px)then begin
          ii:=pred[ii];
          continue;
        end;
        dfs(y,x);
        inc(fk[x],fk[y]);
        if (p[ii])then inc(f[x],fk[y])else inc(f[x],f[y]);
        ii:=pred[ii];
      end;
    end;
  procedure dfs2(x,px,add:longint);
    var
      ii,y:longint;
    begin
      inc(fr[x],add);
      ii:=last[x];
      while (ii>0)do begin
        y:=g[ii];
        if (y=px)then begin
          ii:=pred[ii];
          continue;
        end;
        if (p[ii])then dfs2(y,x,fk[1]-fk[y]) else dfs2(y,x,add+f[x]-f[y]);
        ii:=pred[ii];
      end;
    end;

begin
  read(n);
  for i:=1 to n-1 do begin 
    read(x,y,z);
    
    while (z>0)do begin
      if (z mod 10<>4)and(z mod 10<>7)then break;
      z:=z div 10;
    end;
    
    inc(kg);
    g[kg]:=y;
    p[kg]:=(z=0);
    pred[kg]:=last[x];
    last[x]:=kg;
    
    inc(kg);
    g[kg]:=x;
    p[kg]:=(z=0);
    pred[kg]:=last[y];
    last[y]:=kg;
  end;
  fillchar(f,sizeof(f),$0);
  fillchar(fk,sizeof(fk),$0);
  dfs(1,0);
  for i:=1 to n do fr[i]:=f[i];
  dfs2(1,0,0);
  res:=0;
  for i:=1 to n do res:=res+int64(fr[i]-1)*fr[i];
  writeln(res);
end.