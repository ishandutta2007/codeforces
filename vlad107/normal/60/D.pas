{$M 20000000}
{$r+,q+,s+,i+,o-}
const
  maxn=15000000;
var
  x,y,z,res,n,i,p,q,xx,yy:longint;
  pred:array[0..maxn]of longint;
  function gcd(x,y:longint):longint;
    begin
      while (x>0)and(y>0)do
        if (x>y)then x:=x mod y else y:=y mod x;
      gcd:=x+y;
    end;
  function fs(x:longint):longint;
    begin
      if (x<>pred[x])then pred[x]:=fs(pred[x]);
      fs:=pred[x];
    end;

begin
  //assign(input,'input.txt');reset(input);
  //assign(output,'output.txt');rewrite(output);
  read(n);
  fillchar(pred,sizeof(pred),$0);
  for i:=1 to n do begin
    read(x);
    pred[x]:=x;
  end;
  for p:=1 to maxn do 
    for q:=1 to maxn do begin
      if (q>=p)then break;
      if (int64(p)*p+int64(q)*q>maxn)then break;
      if (gcd(p,q)=1)and(p and 1<>q and 1)
        then begin
          x:=p*p-q*q;
          y:=2*p*q;
          z:=p*p+q*q;
		  if (pred[x]<>0)and(pred[y]<>0)then begin
			xx:=fs(x);
			yy:=fs(y);
			pred[yy]:=xx;
		  end;
		  if (pred[x]<>0)and(pred[z]<>0)then begin
            xx:=fs(x);
			yy:=fs(z);
			pred[yy]:=xx;
		  end;
		  if (pred[y]<>0)and(pred[z]<>0)then begin
			xx:=fs(y);
			yy:=fs(z);
			pred[yy]:=xx;
		  end;
        end;
    end;
  res:=0;
  for i:=1 to maxn do
    if (pred[i]=i)then inc(res);
  writeln(res);
  close(output);close(input);
end.