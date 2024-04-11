{$r-,q-,s-,i-,o+}
const
  base=1000009;
  inf=1000000000;
var
  n,i,ii,res,kha,kg,dl,xx:longint;
  found:boolean;
  w,f,fn,ca,last,pred,g,a:array[0..2005000]of longint;
  stb,hash:array[0..100500]of qword;
begin
//  assign(input,'input.txt');reset(input);
//  assign(output,'output.txt');rewrite(output);
  read(n);
  for i:=1 to n do read(a[i]);
  for i:=1 to n do ca[i]:=a[i];
  kha:=0;
  fillchar(pred,sizeof(pred),$0);
  fillchar(last,sizeof(last),$0);
  for i:=1 to n do begin
    xx:=a[i] mod base;
    ii:=last[xx];
    found:=false;
    while (ii>0)do begin
      if (g[ii]=a[i])then begin
        a[i]:=ii;
        found:=true;
        break;
      end;
      ii:=pred[ii];
    end;
    if (not found)then begin
      inc(kha);
      g[kha]:=a[i];
      a[i]:=kha;
      pred[kha]:=last[xx];
      last[xx]:=kha;
    end;
  end;
  kg:=0;
  fillchar(pred,sizeof(pred),$0);
  fillchar(last,sizeof(last),$0);
  for i:=1 to n do begin
    inc(kg);
    g[kg]:=i;
    pred[kg]:=last[a[i]];
    last[a[i]]:=kg;
  end;
  hash[0]:=0;
  stb[0]:=1;
  for i:=1 to n do stb[i]:=stb[i-1]*base;
  for i:=1 to n do hash[i]:=hash[i-1]+stb[i-1]*a[i];
//
{  for i:=1 to n do write(hash[i],' ');
  writeln;
  for i:=1 to n do write(stb[i],' ');
  writeln;
  writeln(hash[3]*stb[3]);}
//
  for i:=1 to n do w[i]:=inf;
  res:=1;
  for i:=2 to n do begin
    ii:=last[a[i]];
    while (ii>0)do begin
      xx:=g[ii];
      if (xx<i)then begin
        dl:=i-xx;
        if (dl<w[xx])and(i+dl-1<=n)and((hash[i-1]-hash[xx-1])*stb[dl]=hash[i+dl-1]-hash[i-1])then w[xx]:=dl;
      end;
      ii:=pred[ii];
    end;
  end;
{//
  for i:=1 to n do write(w[i],' ');
  writeln;
//}
  f[n+1]:=inf;
  fn[n+1]:=n+1;
  for i:=n downto 1 do begin
    f[i]:=f[i+1];
    fn[i]:=fn[i+1];
    if (w[i]<=f[i])then begin
      f[i]:=w[i];
      fn[i]:=i;
    end;
  end;
{//
  for i:=1 to n do write(f[i],' ');
  writeln;
  for i:=1 to n do write(fn[i],' ');
  writeln;
//}
  res:=1;
  while (f[res]<>inf)do res:=fn[res]+f[res];
  writeln(n-res+1);
  for i:=res to n do write(ca[i],' ');
  writeln;
  close(output);close(input);
end.