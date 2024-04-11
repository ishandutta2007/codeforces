{$r-,q-,s-,i-,o+}
var
  maxn,ss,ff,i,j,n,m:longint;
  res,t:int64;
  r,rev:array[0..500]of longint;
  f:array[0..1 shl 16]of int64;
  men:array[0..500]of longint;
  was:array[0..500]of boolean;
  procedure solve;
    var
      mask,i,x,kx:longint;
    begin
      fillchar(f,sizeof(f),$0);
      f[0]:=1;
      for mask:=0 to maxn-1 do begin
        x:=mask;
        kx:=0;
        while (x>0)do begin
          inc(kx);
          x:=x and (x-1);
        end;
        if (rev[kx+1]<>-1)
          then begin
            ss:=rev[kx+1];
            ff:=rev[kx+1];
          end else begin
            ss:=1;
            ff:=n;
          end;
        for i:=ss to ff do 
          if (mask and (1 shl (i-1))=0)and
             (mask and men[i]=men[i])then inc(f[mask+(1 shl (i-1))],f[mask]);
      end;
      res:=f[maxn];
    end;

begin
//  assign(input,'input.txt');reset(input);
//  assign(output,'output.txt');rewrite(output);
  read(n,t,m);
  maxn:=(1 shl n)-1;
  t:=t-2000;
  fillchar(men,sizeof(men),$0);
  for i:=1 to m do begin
    read(ss,ff);
    men[ff]:=men[ff]or(1 shl (ss-1));
  end;
  fillchar(r,sizeof(r),$FF);
  fillchar(rev,sizeof(rev),$FF);
  solve;
  if (res<t)then begin
    writeln('The times have changed');
    exit;
  end;
  fillchar(was,sizeof(was),false);
  for i:=1 to n do begin  
    for j:=1 to n do begin
      if (was[j])then continue;
      r[i]:=j;
      rev[j]:=i;
      solve;
      if (res>=t)then break;
      t:=t-res;
      rev[j]:=-1;
    end;
    was[r[i]]:=true;
    write(r[i],' ');
  end;
  writeln;
  close(output);close(input);
end.