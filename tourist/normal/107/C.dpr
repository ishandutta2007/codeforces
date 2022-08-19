{R+,S+,Q+,I+,O-}
{$R-,S-,Q-,I-,O+}
var
  lg,rg,nt,ii,n,m,i,ss,ff,t,q: longint;
  found: boolean;
  y: int64;
  f: array [0..66666] of int64;
  p,mask: array [0..22] of longint;
  kb: array [0..66666] of longint;
begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(n,y,m);
  y:=y-2000;
  fillchar(mask,sizeof(mask),0);
  for i:=1 to m do
  begin
    read(ss,ff);
    mask[ff]:=mask[ff] or (1 shl (ss-1));
  end;
  kb[0]:=0;
  for i:=1 to 1 shl n-1 do kb[i]:=kb[i and (i-1)]+1;
  fillchar(p,sizeof(p),0);
  for q:=1 to n do
  begin
    found:=False;
    for ii:=1 to n do
      if p[ii] = 0 then
      begin
        p[ii]:=q;
        fillchar(f,sizeof(f),0);
        f[0]:=1;
        for t:=0 to 1 shl n-2 do
        begin
          lg:=1; rg:=n;
          if p[kb[t]+1] > 0 then
          begin
            lg:=p[kb[t]+1];
            rg:=lg;
          end;
          for i:=lg to rg do
            if t and (1 shl (i-1)) = 0 then
              if t and mask[i] = mask[i] then
              begin
                nt:=t+(1 shl (i-1));
                f[nt]:=f[nt]+f[t];
              end;
        end;
        if f[1 shl n-1] < y then y:=y-f[1 shl n-1] else
        begin
          write(ii);
          found:=True;
          break;
        end;
        p[ii]:=0;
      end;
    if not found then
    begin
      writeln('The times have changed');
      halt;
    end;
    if q < n then write(' ');
  end;
  writeln;
  close(input);
  close(output);
end.