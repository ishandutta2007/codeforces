{$r-,q-,s-,i-,o+}
const
  maxn=1000100;
  base=1000000007;

var
  f,g,a,sa:array[0..1000500]of longint;
  ans,n,i:longint;

  function findsum(x:longint):longint;
    var
      res:longint;
      
    begin
      res:=0;
      while (x>0)do begin
        inc(res,sa[x]);
        if (res>=base)then dec(res,base);
        x:=x and (x-1);
      end;
      findsum:=res;
    end;

  procedure modify(x,y:longint);
    begin
      while (y<0)do inc(y,base);
      while (x<=maxn)do begin
        inc(sa[x],y);
        if (sa[x]>=base)then dec(sa[x],base);
        x:=x or (x-1)+1;
      end;
    end;

begin
  read(n);
  ans:=0;
  fillchar(g,sizeof(g),$0);
  for i:=1 to n do begin
    read(a[i]);
    f[i]:=findsum(a[i])+1;
    if (f[i]>=base)then dec(f[i],base);
    f[i]:=int64(f[i])*a[i] mod base;
    modify(a[i],-g[a[i]]+f[i]);
    g[a[i]]:=f[i];
  end; 
  fillchar(g,sizeof(g),$0);
  for i:=n downto 1 do 
    if (g[a[i]]=0)then begin
      inc(ans,f[i]);
      if (ans>=base)then dec(ans,base);
      g[a[i]]:=1;
    end;
  writeln(ans);
end.