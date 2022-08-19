{$R-,S-,Q-,I-,O+}
var
  tt,qq: longint;
  k,l,p,r,w,q,d,a,b,ans: int64;

function pow(a,b,c:int64):int64;
var
  step,x: int64;
begin
  step:=int64(1) shl 62;
  x:=1;
  while step > 0 do
  begin
    x:=x*x mod c;
    if step and b <> 0 then x:=x*a mod c;
    step:=step shr 1;
  end;
  pow:=x;
end;

begin
  read(tt);
  for qq:=1 to tt do
  begin
    read(k,l,r,p);
    w:=pow(2,l,p-1);
    if w = 0 then w:=p-1;
    q:=pow(k,w,p);
    if q = 0 then ans:=1 else
    if q = 1 then ans:=pow(2,r-l+1,p) else
    begin
      d:=pow(2,r+1,p-1);
      if d = 0 then d:=p-1;
      a:=(pow(k,d,p)+p-1) mod p;
      b:=pow(q-1,p-2,p);
      ans:=a*b mod p;
    end;
    if k and 1 = 1 then
      if p = 2 then ans:=0 else
      begin
        d:=pow(2,r-l,p);
        b:=pow(d,p-2,p);
        ans:=ans*b mod p;
      end;
    writeln(ans);
  end;
end.