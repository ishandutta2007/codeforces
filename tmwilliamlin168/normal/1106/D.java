import java.util.Collections;
import java.util.LinkedList;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Scanner;

public class Solution {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int n = scan.nextInt(), m = scan.nextInt();
		Node[] nodes = new Node[n];
		for(int i=0;i<n;i++)nodes[i]=new Node(i);
		for(int i=0;i<m;i++) {
			int u=scan.nextInt()-1,v=scan.nextInt()-1;
			nodes[v].children.add(nodes[u]);
			nodes[u].children.add(nodes[v]);
		}
		for(int i=0;i<n;i++)
			nodes[i].sort();
		bfs(nodes[0]);
		System.out.println();
		scan.close();
	}
	private static void bfs(Node node) {
		PriorityQueue<Node> queue = new PriorityQueue<>();
		queue.add(node);
		while(!queue.isEmpty()) {
			node = queue.remove();
			if (!node.visited) {
				System.out.print(node.index+1);
				System.out.print(" ");
				for (Node n:node.children)
					if(!n.visited)queue.add(n);
				node.visited=true;
			}
		}
	}
	private static void dfs(Node node) {
		if (node.visited) return;
		System.out.print(node.index+1);
		System.out.print(" ");
		node.visited=true;
		for (Node n:node.children)
			if(!n.visited)dfs(n);
	}
	static class Node implements Comparable<Node> {
		int index;
		boolean visited=false;
		List<Node> children = new LinkedList<>();
		public Node(int i) {index=i;		}
		public void sort() {
			Collections.sort(children);
		}
		@Override
		public int compareTo(Node o) {
			return index-o.index;
		}
	}
}