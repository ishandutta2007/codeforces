var
  r,a,b,m,i:longint;
  time:array[0..500500]of longint;

begin
  read(a,b,m,r);
  fillchar(time,sizeof(time),$FF);
  for i:=1 to m+5 do begin
    r:=(a*r+b)mod m;
    if (time[r]<>-1)then begin
      writeln(i-time[r]);
      exit;
    end;
    time[r]:=i;
  end;
end.