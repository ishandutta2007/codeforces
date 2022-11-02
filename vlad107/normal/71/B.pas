var
  i,n,k,t,sum:longint;

begin
  read(n,k,t);
  sum:=0;
  while (true)do begin
    if (sum*100<=t*n*k)and(t*n*k<(sum+1)*100)then break;
    inc(sum);
  end;
  for i:=1 to n do 
    if (sum<=k)
      then begin
        write(sum,' ');
        sum:=0;
      end else begin
        write(k,' ');
        dec(sum,k);
      end;
end.