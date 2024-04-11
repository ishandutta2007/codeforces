var
  nj,max,ii,cr,kg,tmp,m,n,v,i,j,tj:longint;
  ka,g,pred,last,a,l,r,t,nom:array[0..500500]of longint;
  f,px,py:array[0..444,0..444]of longint;
  e:array[0..444,0..444]of longint;

begin
  assign(input,'input.txt');reset(input);
  assign(output,'output.txt');rewrite(output);
  read(n,v);
  for i:=1 to n do read(a[i]);
  read(m);
  for i:=1 to m do read(l[i],r[i],t[i]);
  for i:=1 to m do nom[i]:=i;
  for i:=1 to m-1 do 
    for j:=1 to m-1 do
      if (t[j]<t[j+1])then begin
        tmp:=l[j];l[j]:=l[j+1];l[j+1]:=tmp;
        tmp:=r[j];r[j]:=r[j+1];r[j+1]:=tmp;
        tmp:=t[j];t[j]:=t[j+1];t[j+1]:=tmp;
        tmp:=nom[j];nom[j]:=nom[j+1];nom[j+1]:=tmp;
      end;
  for i:=1 to m do 
    for j:=l[i] to r[i] do begin
      inc(kg);
      g[kg]:=i;
      pred[kg]:=last[j];
      last[j]:=kg;
    end;
  fillchar(f,sizeof(f),$ff);
  f[1][0]:=0;
  for i:=1 to n do 
    for j:=0 to 400 do 
      if (f[i][j]>=0)then begin
        tj:=j-v+a[i];
        if (tj<0)then continue;
        nj:=tj;
        if (a[i]<nj)then nj:=a[i];
        if (f[i][j]>f[i+1][nj])then begin
          f[i+1][nj]:=f[i][j];
          px[i+1][nj]:=0;
          py[i+1][nj]:=j;
        end;
        cr:=0;
        ii:=last[i];
        while (ii>0)do begin
          dec(tj,t[g[ii]]);
          if (tj<0)then break;
          inc(cr);
          nj:=tj;
          if (a[i]<nj)then nj:=a[i];
          if (cr+f[i][j]>f[i+1][nj])then begin
            f[i+1][nj]:=cr+f[i][j];
            px[i+1][nj]:=cr;
            py[i+1][nj]:=j;
          end;
          ii:=pred[ii];
        end;
      end;
  max:=0;
  for i:=0 to 400 do 
    if (f[n+1][i]>max)then begin
      max:=f[n+1][i];
      j:=i;
    end;
  writeln(Max);
  for i:=n+1 downto 1 do begin
    ii:=last[i-1];
    for tj:=1 to px[i][j] do begin
      inc(ka[i-1]);
      e[i-1][ka[i-1]]:=nom[g[ii]];
      ii:=pred[ii];
    end;
    j:=py[i][j];
  end;
  for i:=1 to n do begin
    write(ka[i],' ');
    for j:=1 to ka[i] do write(e[i][j],' ');
    writeln;
  end;
end.