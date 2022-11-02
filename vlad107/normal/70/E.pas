{$r-,q-,s-,i-,o+}
const
  inf=1000000000;
var
  h,g,gp,last,pred,predp,lastp,ptr,r1,r2,st,d:array[0..100500]of longint;
  f,gf:array[0..500,0..500]of int64;
  x,y,n,kt,i,kg,kp:longint;
  function min(x,y:longint):longint;
    begin
      if (x<y)then min:=x else min:=y;
    end;
  procedure predfs(x,px:longint);
    var
      i,ii:longint;
    begin
      h[x]:=h[px]+1;
      ptr[x]:=px;
      inc(st[0]);
      st[st[0]]:=x;
      for i:=1 to st[0] do begin
        inc(kp);
        gp[kp]:=x;
        predp[kp]:=lastp[st[i]];
        lastp[st[i]]:=kp;
      end;
      ii:=last[x];
      while (ii>0)do begin
        if (g[ii]<>px)then predfs(g[ii],x);
        ii:=pred[ii];
      end;
      dec(st[0]);
    end;
  procedure dfs(x,k:longint);
    var
      i2,y,ii,i,j,dl,cr:longint;
    begin
      if (f[x][k]<>-1)then exit;
      if (k<n)then begin
        ii:=lastp[x];
        f[x][k]:=0;
        while (ii>0)do begin
          y:=gp[ii];
          inc(f[x][k],d[k+h[y]-h[x]]);
          ii:=predp[ii];
        end;
      end else f[x][k]:=inf;
      ii:=lastp[x];
      while (ii>0)do begin
        y:=gp[ii];
        i:=y;
        j:=-1;
        dl:=0;
        cr:=kt;
        while (j<>x)do begin
          i2:=last[i];
          inc(cr,d[min(dl,k+h[i]-h[x])]);
          while (i2>0)do begin
            if (g[i2]<>ptr[i])and(g[i2]<>j)then begin
              dfs(g[i2],min(dl,k+h[i]-h[x])+1);
              inc(cr,f[g[i2]][min(dl,k+h[i]-h[x])+1]);
            end;
            i2:=pred[i2];
          end;
          j:=i;
          i:=ptr[i];
          inc(dl);
        end;
        if (cr<f[x][k])then begin
          f[x][k]:=cr;
          gf[x][k]:=y;
        end;
        ii:=predp[ii];
      end;
    end;                       
  procedure labdfs(x,y,k:longint);
    var
      ii:longint;
    begin
      if (k<r1[x])then begin
        r1[x]:=k;
        r2[x]:=y;
      end else exit;
      ii:=last[x];
      while (ii>0)do begin
        labdfs(g[ii],y,k+1);
        ii:=pred[ii];
      end;
    end;
  procedure outdfs(x,k:longint);
    var
      i2,y,i,j,dl:longint;
    begin
      if (gf[x][k]<0)then exit;
      y:=gf[x][k];
      labdfs(y,y,0);
      i:=y;
      j:=-1;
      dl:=0;
      while (j<>x)do begin
        i2:=last[i];
        while (i2>0)do begin
          if (g[i2]<>ptr[i])and(g[i2]<>j)then outdfs(g[i2],min(dl,k+h[i]-h[x])+1);
          i2:=pred[i2];
        end;
        j:=i;
        i:=ptr[i];
        inc(dl);
      end;
    end;
begin
//  assign(input,'input.txt');reset(input);
//  assign(output,'output.txt');rewrite(output);
  read(n,kt);
  for i:=1 to n-1 do read(d[i]);
  for i:=n to n+n do d[i]:=inf;
  d[0]:=0;
  kg:=0;
  fillchar(last,sizeof(last),$0);
  for i:=1 to n-1 do begin
    read(x,y);
    inc(kg);g[kg]:=y;pred[kg]:=last[x];last[x]:=kg;
    inc(kg);g[kg]:=x;pred[kg]:=last[y];last[y]:=kg;
  end;
  h[0]:=-1;
  fillchar(f,sizeof(f),$FF);
  fillchar(gf,sizeof(gf),$FF);
  st[0]:=0;
  kp:=0;
  predfs(1,0);
  dfs(1,n);
  writeln(f[1][n]);
  for i:=1 to n do r1[i]:=inf;
  for i:=1 to n do r2[i]:=-1;
  outdfs(1,n);
  for i:=1 to n do write(r2[i],' ');
  writeln;
end.