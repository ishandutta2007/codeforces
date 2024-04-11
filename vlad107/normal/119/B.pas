{$r-,q-,s-,i-,o+}
{$M 100000000}
const
  inf=1000000000;
var
  kq,m,j,tt,cr,min,max,n,k,i,q,x,sum:longint;
  used:array[0..500050]of boolean;
  a,kt:array[0..500050]of longint;

begin
//  assign(input,'input.txt');reset(input);
//  assign(output,'output.txt');rewrite(output);
  read(n,k);
  m:=n div k;
  for i:=1 to n do read(a[i]);
  read(q);

  fillchar(used,sizeof(used),false);
  min:=inf;
  max:=-inf;
  kq:=0;
  for i:=1 to q do begin
    sum:=0;
    for j:=1 to m do begin
      read(x);
      if (j=1)and(not used[x])then inc(kq);
      inc(sum,a[x]);
      used[x]:=true;
    end;
    if (sum<min)then min:=sum;
    if (sum>max)then max:=sum;
  end;

  if (kq=k)then begin
    writeln(min/m:0:7,' ',max/m:0:7);
    exit;
  end;

  fillchar(kt,sizeof(kt),$0);
  for i:=1 to n do
    if (not used[i])then inc(kt[a[i]]);

  cr:=0;
  tt:=m;
  for i:=0 to 1000 do begin
    if (kt[i]>=tt)then begin
      cr:=cr+tt*i;
      break;
    end;
    cr:=cr+kt[i]*i;
    dec(tt,kt[i]);
  end;
  if (cr<min)then min:=cr;

  cr:=0;
  tt:=m;
  for i:=1000 downto 0 do begin
    if (kt[i]>=tt)then begin
      cr:=cr+tt*i;
      break;
    end;
    cr:=cr+kt[i]*i;
    dec(tt,kt[i]);
  end;
  if (cr>max)then max:=cr;
  writeln(min/m:0:7,' ',max/m:0:7);
  close(output);close(input);
end.