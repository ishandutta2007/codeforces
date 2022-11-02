{$r-,q-,s-,i-,o+}
const
  mpr:array[1..21]of longint=(2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73);
var
  kol,q,res,mask,a,b,k,i:longint;
  used,pr:array[0..25000050]of boolean;
  function solve(n:longint):longint;
    var
      cr,i,j:longint;
    begin
      fillchar(pr,sizeof(pr),true);
      fillchar(used,sizeof(used),false);
      for i:=2 to n div k do begin
        if (i>=k)then break;
        if (pr[i])then begin
          j:=1;
          while (int64(i)*j*k<=n)do begin
            used[i*j]:=true;
            inc(j);
          end;
          for j:=2 to n div (k*i)do pr[i*j]:=false;
        end;
      end;
      cr:=0;
      for i:=1 to n div k do
        if (not used[i])then inc(cr);
      solve:=cr;
    end;
begin
  read(a,b,k);
  if (k>b)then begin
    writeln(0);
    exit;
  end;
  i:=2;
  while (i*i<=k)do begin
    if (k mod i=0)then begin
      writeln(0);
      exit;
    end;
    inc(i);
  end;
  if (k>79)then begin
    writeln(solve(b)-solve(a-1));
    exit;
  end;
  res:=0;
  for mask:=0 to 1 shl 21-1 do begin
    q:=k;
    kol:=0;
    for i:=0 to 20 do
      if (mpr[1+i]<k)and(mask and (1 shl i)>0)
        then begin
          if (int64(q)*mpr[1+i]>b)then begin
            kol:=-1;break;
          end;
          q:=q*mpr[1+i];
          inc(kol);
        end else
      if (mpr[1+i]>=k)and(mask and (1 shl i)>0)then begin
        kol:=-1;
        break;
      end;
    if (kol<0)then continue;
    if (kol and 1=0)
      then inc(res,(b div q)-(a-1)div q)
      else dec(res,(b div q)-(a-1)div q);
  end;
  writeln(res);
end.