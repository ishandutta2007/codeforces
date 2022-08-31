{R+,S+,Q+,I+,O-}
{$R-,S-,Q-,I-,O+}
var
  n,i,j,q,ii,min,km,mn,cc: longint;
  a: array [0..333,0..333] of longint;
  b: array [0..333] of longint;
begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(n);
  for i:=1 to n do
    for j:=1 to n do
    begin
      read(q);
      a[i,q]:=j;
    end;
  for i:=1 to n do
  begin
    read(q);
    b[q]:=i;
  end;
  for ii:=1 to n do
  begin
    min:=n+1; km:=0;
    for i:=1 to n do
    begin
      if (ii = 1) and (i = 1) then continue;
      mn:=n+1; cc:=0;
      for j:=1 to i do
        if (j <> ii) and (b[j] < mn) then
        begin
          mn:=b[j];
          cc:=j;
        end;
      if a[ii,cc] < min then
      begin
        min:=a[ii,cc];
        km:=i;
      end;
    end;
    write(km);
    if ii < n then write(' ');
  end;
  writeln;
//  close(input);
//  close(output);
end.