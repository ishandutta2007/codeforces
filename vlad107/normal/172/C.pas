{$r-,q-,s-,i-,o+}
const
  maxn=100000;

var
  maxx,tt,mm,n,m,i,j,ff:longint;
  cs,fs,t,x,sum:array[0..500500]of longint;

  procedure add(x,val:longint);
    begin
      while (x<=maxn)do begin
        inc(sum[x],val);
        x:=x or (x-1)+1;
      end;
    end;
    
  function fsum(x:longint):longint;
    var
      res:longint;
      
    begin
      res:=0;
      while (x>0)do begin
        inc(res,sum[x]);
        x:=x and (x-1);
      end;
      fsum:=res;
    end;

begin
  read(n,m);
  for i:=1 to n do read(t[i],x[i]);
  fillchar(sum,sizeof(sum),$0);
  fillchar(cs,sizeof(cs),$0);
  i:=1;
  tt:=0;
  while (i<=n)do begin
    if (i+m>n)
      then ff:=n
      else ff:=i+m-1;
    for j:=i to ff do inc(cs[x[j]]);
    if (t[ff]>tt)then tt:=t[ff];
    maxx:=0;
    for j:=i to ff do 
      if (cs[x[j]]>0)then begin
        fs[x[j]]:=1+cs[x[j]]shr 1;
        if (x[j]>maxx)then maxx:=x[j];
        add(x[j],+fs[x[j]]);
        cs[x[j]]:=0;
      end;
    for j:=i to ff do write(tt+x[j]+fsum(x[j]-1),' ');
    tt:=tt+fsum(maxn)+2*maxx;
    
    for j:=i to ff do 
      if (fs[x[j]]>0)then begin
        add(x[j],-fs[x[j]]);
        fs[x[j]]:=0;
      end;
    i:=ff+1;
  end;
  writeln;
end.