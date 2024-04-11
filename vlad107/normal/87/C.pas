{$r-,q-,s-,i-,o+}
var
  xx,kk,a,n,qqq,i,j,k,tk:longint;
  was,g,gx:array[0..500500]of longint;
begin
  read(n);
  fillchar(g,sizeof(g),$0);
  fillchar(was,sizeof(was),$0);
  qqq:=0;
  gx[0]:=0;
  kk:=1000000000;
  for i:=1 to n do begin
    k:=2;
    inc(qqq);
    while (k*k<=2*i)do begin
      if (2*i mod k=0)then begin
        xx:=(2*i div k)-k+1;
        if (xx>1)and(xx mod 2=0)then begin
          a:=xx div 2;
          if (gx[a+k-1]xor gx[a-1]=0)and(k<kk)and(i=n)then kk:=k;
          was[gx[a+k-1]xor gx[a-1]]:=qqq;
        end;
        tk:=2*i div k;
        if (tk<>k)then begin
          xx:=(2*i div tk)-tk+1;
          if (xx>1)and(xx mod 2=0)then begin
            a:=xx div 2;
            if (gx[a+tk-1]xor gx[a-1]=0)and(tk<kk)and(i=n)then kk:=tk;
            was[gx[a+tk-1]xor gx[a-1]]:=qqq;
          end;
        end;
      end;
      inc(k);
    end;
    j:=0;
    while (was[j]=qqq)do inc(j);
    g[i]:=j;
    gx[i]:=gx[i-1]xor j;
  end;
  if (g[n]=0)
    then writeln(-1)
    else writeln(kk);
end.