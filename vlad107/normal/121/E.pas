{$r-,q-,s-,i-,o+}
const
  maxa=10001;
  maxn=100500;

var
  luck:array[1..maxa+5]of boolean;
  i,x,tt,n,l,r,d:longint;
  ch:char;
  sum,a:array[0..maxn+10]of longint;

  procedure add(x,val:longint);  
    begin
      while (x<=maxn)do begin
        inc(sum[x],val);
        x:=x or (x-1)+1;
      end;
    end;

  function findsum(x:longint):longint;
    var
      res:longint;

    begin
      res:=0;
      while (x>0)do begin
        inc(res,sum[x]);
        x:=x and (x-1);
      end;
      findsum:=res;
    end;

begin
  for i:=1 to maxa do begin
    luck[i]:=true;
    x:=i;
    while (x>0)do begin
      if (x mod 10=4)or(x mod 10=7)then begin
        x:=x div 10;
        continue;
      end;
      luck[i]:=false;
      break;
    end;
  end;

  readln(n,tt);
  for i:=1 to n do read(a[i]);
  readln;
  fillchar(sum,sizeof(sum),$0);;
  for i:=1 to n do 
    if (luck[a[i]])then add(i,+1);
  while (tt>0)do begin
    dec(tt);
    read(ch);
    if (ch='a')then begin
      readln(ch,ch,l,r,d);
      for i:=l to r do begin 
        x:=a[i]+d;
        if (luck[a[i]])and(not luck[x])then add(i,-1);
        if (luck[x])and(not luck[a[i]])then add(i,+1);
        a[i]:=x;
      end;
    end else begin
      readln(ch,ch,ch,ch,l,r);
      writeln(findsum(r)-findsum(l-1));
    end;
  end;
end.