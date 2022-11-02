{$r-,q-,s-,i-,o+}
const
  inf=1000000000;
  uff=10000000;
  eps=1e-9;

var
  s3,kol,st,u,s1,s2,ans:extended;
  x,y,xx,yy:array[0..500500]of longint;
  tt,maxx,nj1,nj2,j1,j2,ss,ff,tmp,v,i,minx,miny,n,m:longint;
  
  function next(x:longint):longint;
    begin
      inc(x);
      if (x>n)then x:=1;
      next:=x;
    end;
    
  function prev(x:longint):longint;
    begin
      dec(x);
      if (x=0)then x:=n;
      prev:=x;
    end;
  
  procedure solve;
    begin
      minx:=inf;miny:=-inf;
      maxx:=-inf;
      for i:=1 to n do begin
        if (x[i]<minx)or(x[i]=minx)and(y[i]>miny)then begin
          v:=i;
          minx:=x[i];
          miny:=y[i];
        end;
        if (x[i]>maxx)then maxx:=x[i];
      end;
      x[n+1]:=x[1];y[n+1]:=y[1];
      m:=1;
      xx[1]:=x[v];yy[1]:=y[v];
      if (y[v+1]>=y[v])then begin
        i:=next(v);
        while (i<>v)do begin
          inc(m);
          xx[m]:=x[i];yy[m]:=y[i];
          i:=next(i);
        end;
      end else begin
        i:=prev(v);
        while (i<>v)do begin
          inc(m);
          xx[m]:=x[i];yy[m]:=y[i];
          i:=prev(i);
        end;
      end;
      for i:=1 to n do begin
        x[i]:=xx[i];
        y[i]:=yy[i];
      end;
      tt:=1;
      for i:=2 to n do
        if (x[i]>x[tt])then tt:=i;
      j1:=1;
      j2:=1;
      s1:=0;s2:=0;s3:=0;
      for i:=minx to maxx do begin
        while (j1<tt)and(i>x[next(j1)])do j1:=next(j1);
        while (prev(j2)>tt)and(i>=x[prev(j2)])do j2:=prev(j2);
          nj1:=next(j1);
          nj2:=prev(j2);
          if (i=x[j1])
            then ff:=y[j1]
            else begin
              st:=(y[nj1]-y[j1])/(x[nj1]-x[j1]);
              ff:=trunc(y[j1]+st*(i-x[j1])+eps);
            end;
          if (i=x[j2])
            then ss:=y[j2]
            else begin
              st:=(y[nj2]-y[j2])/(x[nj2]-x[j2]);
              ss:=trunc(y[j2]+st*(i-x[j2])+1-eps);
            end;
          u:=ff-ss+1;
        ans:=ans+u*(s1+s2*i*i-2*s3*i);
        s1:=s1+u*i*i;
        s2:=s2+u;
        s3:=s3+u*i;
      end;
      kol:=s2;
    end;

begin
  //assign(input,'input.txt');reset(Input);
  //assign(output,'output.txt');rewrite(output);
  read(n);
  for i:=1 to n do read(x[i],y[i]);
  for i:=1 to n do begin
    x[i]:=x[i]+uff;
    y[i]:=y[i]+uff;
  end;
  ans:=0;
  solve;
  for i:=1 to n do begin
    tmp:=x[i];x[i]:=y[i];y[i]:=tmp;
  end;
  solve;
  ans:=ans/((kol-1)*(kol));
  writeln(ans:0:10);
end.