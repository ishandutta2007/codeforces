
{$M 10000000}
const 
  ABC='ACGT';
  base=1000000009;
var
  kolnum:longint;
  s:string;
  nexto,j,n,m,kb,i,x,o:longint;
  pow,link,pred,predch:array[0..555]of longint;
  leaf:array[0..555]of boolean;
  next:array[0..555,0..5]of longint;
  f:array[0..1111,0..11,0..111]of longint;
  procedure recl(x:longint);
    var
      i,ch:longint;
    begin
      if (link[x]<>-1)then exit;
      if (pred[x]=0)then begin
        link[x]:=0;
        exit;
      end;
      ch:=predch[x];
      i:=pred[x];
      if (link[i]=-1)then recl(i);
      i:=link[i];
      while (i>0)and(next[i][ch]=-1)do begin
        if (link[i]=-1)then recl(i);
        i:=link[i];
      end;
      if (next[i][ch]=-1)
        then i:=0
        else i:=next[i][ch];
      link[x]:=i;
    end;
  function next_bor(x,ch:longint):longint;
    begin
      while (x>0)and(next[x][ch]=-1)do x:=link[x];
      next_bor:=next[x][ch];
    end;
  function rec(i,k,x:longint):longint;
    var
      si,sk,sx,tt,nextx,ch,res:longint;
    begin
      if (f[i][k][x]<>-1)then begin
        rec:=f[i][k][x];
        exit;
      end;
      si:=i;sk:=k;sx:=x;
      if (pow[x]<k)then begin
        f[si][sk][sx]:=0;
        rec:=0;
        exit;
      end;
      tt:=x;
      while (tt>0)and(pow[tt]>=k)do begin
        if (leaf[tt])then begin
          k:=0;
          break;
        end;
        tt:=link[tt];
      end; 
      if (i=n+1)and(k=0)then begin
        f[si][sk][sx]:=1;
        rec:=1;
        exit;
      end;
      if (i=n+1)then begin
        f[si][sk][sx]:=0;
        rec:=0;
        exit;
      end;
      res:=0;
      for ch:=1 to 4 do begin
        nextx:=next_bor(x,ch);
        if (nextx<0)then continue;
        res:=res+rec(i+1,k+1,nextx);
        if (res>=base)then dec(res,base);
      end;
      f[si][sk][sx]:=res;
      rec:=res;
      exit;
    end;
begin
  //assign(input,'input.txt');reset(input);
  //assign(output,'output.txt');rewrite(output);
  readln(n,m);
  kb:=0;
  fillchar(next,sizeof(next),$FF);
  fillchar(link,sizeof(link),$FF);
  fillchar(leaf,sizeof(leaf),false);
  link[0]:=0;
  pow[0]:=0;
  for i:=1 to m do begin
    readln(s);
    if (length(s)>n)then continue;
    x:=0;
    for j:=1 to length(s)do begin
      o:=pos(s[j],ABC);
      if (next[x][o]=-1)then begin
        inc(kb);
        next[x][o]:=kb;        
      end;
      nexto:=next[x][o];
      pred[nexto]:=x;
      predch[nexto]:=o;
      pow[nexto]:=pow[x]+1;
      x:=nexto;
    end;
    leaf[x]:=true;
  end;
  for i:=0 to kb do recl(i);
  fillchar(f,sizeof(f),$FF);
  writeln(rec(1,0,0));
end.