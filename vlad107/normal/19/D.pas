{$r-,q-,s-,i-o+}
{$M 10000000}
type
  TTree=record
    l,r,maxy:longint;
  end;
const
  maxn=400500;
var
  ch:char;
  kn,nn,xx,yy,n,i:longint;
  found:boolean;
  revtr,xtr,ytr,x,y,quest:array[0..maxn]of longint;
  tr:array[0..4*maxn]of TTree;
  procedure qs(l,r:longint);
    var
      i,j,xx,yy,tmp:longint;
    begin
      i:=l;j:=r;
      nn:=l+random(r-l+1);
      xx:=xtr[nn];
      yy:=ytr[nn];
      while (i<=j)do begin
        while (xx>xtr[i])or(xx=xtr[i])and(yy>ytr[i])do inc(i);
        while (xx<xtr[j])or(xx=xtr[j])and(yy<ytr[j])do dec(j);
        if (i>j)then break;
        tmp:=xtr[i];xtr[i]:=xtr[j];xtr[j]:=tmp;
        tmp:=ytr[i];ytr[i]:=ytr[j];ytr[j]:=tmp;
        inc(i);dec(j);
      end;
      if (i<r)then qs(i,r);
      if (j>l)then qs(l,j);
    end;
  procedure build(x,l,r:longint);
    begin
      tr[x].l:=l;tr[x].r:=r;
      tr[x].maxy:=-1;
      if (l=r)
        then revtr[l]:=x
        else begin
          build(x+x,l,(l+r)shr 1);
          build(x+x+1,(l+r)shr 1+1,r);
        end;
    end;
  procedure findmax(x:longint);
    begin
      if (tr[x].maxy<=yy)then exit;
      if (xtr[tr[x].r]<=xx)then exit;
      if (found)then exit;
      if (tr[x].l=tr[x].r)then begin
        writeln(xtr[tr[x].l],' ',ytr[tr[x].r]);
        found:=true;
        exit;
      end;
      findmax(x+x);
      findmax(x+x+1);
    end;
  function findnom(xx,yy:longint):longint;
    var
      l,r:longint;
    begin
      l:=1;r:=kn;
      while (l<r-1)do
        if (xtr[(l+r)shr 1]>xx)or(xtr[(l+r)shr 1]=xx)and(ytr[(l+r)shr 1]>yy)
          then r:=(l+r)shr 1
          else l:=(l+r)shr 1;
      if (xtr[l]=xx)and(ytr[l]=yy)
        then findnom:=l
        else findnom:=r;
    end;
begin
  randomize;
  //assign(input,'input.txt');reset(input);
  //assign(output,'output.txt');rewrite(output);
  read(n);
  for i:=1 to n do begin
    read(ch);
    while not(ch in ['a'..'z'])do read(ch);
    if (ch='a')then quest[i]:=1 else
    if (ch='r')then quest[i]:=2 else
    quest[i]:=3;
    while (ch in ['a'..'z'])do read(ch);
    read(x[i],y[i]);
    xtr[i]:=x[i];ytr[i]:=y[i];
  end;
  qs(1,n);
  kn:=1;
  for i:=2 to n do 
    if (xtr[i]<>xtr[i-1])or(ytr[i]<>ytr[i-1])
      then begin
        inc(kn);
        xtr[kn]:=xtr[i];
        ytr[kn]:=ytr[i];
      end;
  build(1,1,kn);
  for i:=1 to n do 
    if (quest[i]=1)then begin
      xx:=findnom(x[i],y[i]);
      xx:=revtr[xx];
      tr[xx].maxy:=y[i];
      while (xx>1)do begin
        xx:=xx shr 1;
        tr[xx].maxy:=tr[xx+xx].maxy;
        if (tr[xx+xx+1].maxy>tr[xx].maxy)
          then tr[xx].maxy:=tr[xx+xx+1].maxy;
      end;
    end else
    if (quest[i]=2)then begin
      xx:=findnom(x[i],y[i]);
      xx:=revtr[xx];
      tr[xx].maxy:=-1;
      while (xx>1)do begin
        xx:=xx shr 1;
        tr[xx].maxy:=tr[xx+xx].maxy;
        if (tr[xx+xx+1].maxy>tr[xx].maxy)
          then tr[xx].maxy:=tr[xx+xx+1].maxy;
      end;
    end else begin
      xx:=x[i];yy:=y[i];
      found:=false;
      findmax(1);
      if (not found)then writeln(-1);
    end;
  close(output);close(input);
end.